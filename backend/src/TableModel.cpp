#include "TableModel.h"

int TableModel::rowCount(const QModelIndex&) const { return model.length(); }

int TableModel::columnCount(const QModelIndex&) const { return 2; }

QVariant TableModel::data(const QModelIndex& index, int role) const {
    QTime time;

    if (index.column() == 0) {
        time = model[index.row()].first;
    } else {
        time = model[index.row()].second;
    }

    if (role == Qt::DisplayRole) {
        return QString("%1").arg(time.toString());
    }

    return QVariant();
}

QHash<int, QByteArray> TableModel::roleNames() const {
    return {{Qt::DisplayRole, "display"}};
}

TableModel::TableModel(QObject* parent) {
    Q_UNUSED(parent)
    model.append(
        qMakePair(QTime::fromString("08:00"), QTime::fromString("12:00")));
    model.append(
        qMakePair(QTime::fromString("12:30"), QTime::fromString("15:35")));
    model.append(
        qMakePair(QTime::fromString("15:45"), QTime::fromString("18:00")));
}
