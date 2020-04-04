#ifndef WORKBUDDY_TABLEMODEL_H
#define WORKBUDDY_TABLEMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include <QPair>
#include <QTime>

class TableModel : public QAbstractTableModel {
    Q_OBJECT

    QList<QPair<QTime, QTime>> model;

   public:
    explicit TableModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex&) const override;

    int columnCount(const QModelIndex&) const override;

    QVariant data(const QModelIndex& index, int role) const override;

    QHash<int, QByteArray> roleNames() const override;
};

#endif  // WORKBUDDY_TABLEMODEL_H
