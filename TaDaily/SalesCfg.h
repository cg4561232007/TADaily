#ifndef SALESCFG_H
#define SALESCFG_H

#include "ui_salescfg.h"

#include "qwidget.h"
#include "qdir.h"
#include "qtextstream.h"
#include "qfiledialog.h"
#include "qlistview.h"
#include "qtreeview.h"
#include "qmessagebox.h"

QT_BEGIN_NAMESPACE
class QComboBox;
class QTableWidget;
QT_END_NAMESPACE

class SalesCfg : public QWidget,private Ui::Form
{
	Q_OBJECT

public:
	SalesCfg(QString cfg_name, QWidget *parent = 0);
	~SalesCfg();
	
private:
	QString name, id, ser, fpath, tpath;
	QString m_cfg_name;

	private slots:
	void fromAdd();
	void toAdd();
	void configue();

	public slots :
	void setInfo(const QStringList&);

signals:
	void add_tb_item(const QStringList&);

private:
	int isDigit(const QString&);
	void writeFile(QTextStream& ,QTextStream&, QString);

};

#endif // SALESCFG_H
