#ifndef ITEMVIEW_H
#define ITEMVIEW_H

#include <QWidget>
#include "ui_ItemView.h"
class QAbstractItemModel;
class QSortFilterProxyModel;

class ItemView : public QWidget
{
	Q_OBJECT

public:
	ItemView(/*int column, */QWidget *parent = 0);
	~ItemView();
	void setProxy(QSortFilterProxyModel* proxy);
//	void setDataModel(QAbstractItemModel* data);
	void addData(int row, int column, const QVariant& data);
	void setHeaderData(int column, const QVariant& data);
	void clearData();
	void initDataModel(int column);

protected:
	Ui::ItemViewClass ui;

private:
	int m_column;
	QAbstractItemModel* m_DataModel;
	QSortFilterProxyModel* m_sortProxyModel;

private slots:
	void changeRegExp(QRegExp & exp);
	void changeFilterColumn(int col);
	void changeSortCase(int caseSen);
};

#endif // ITEMVIEW_H