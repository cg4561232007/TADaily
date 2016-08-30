#ifndef TADAILY_H
#define TADAILY_H

#include <QtWidgets/QMainWindow>
#include "ui_tadaily.h"
#include "qdebug.h"
#include "qstandarditemmodel.h" 
#include "qmessagebox.h"
#include "qscrollbar.h"
#include "qfiledialog.h"
#include "qlistview.h"
#include "qtreeview.h"
#include "qprogressbar.h"
#include "qaction.h"
#include "qprogressdialog.h"

#include "SalesCfg.h"
#include "defdatetimeedit.h"

#include <string>

using std::string;

QT_BEGIN_NAMESPACE
class QString;
class QPushButton;
class QTableView;
class QTableWidget;
QT_END_NAMESPACE

typedef enum{ JY, LOF, TA, LCJ } CONTENT;
typedef enum{ MORNING, NOON, NIGHT } TIME;

class TaDaily : public QMainWindow, private Ui::TaDailyClass
{
	Q_OBJECT
public:
	TaDaily(QWidget *parent = 0);
	~TaDaily();

protected:
	void closeEvent(QCloseEvent *event) override;

	private slots:
	void fromAdd();
	void toAdd();
	void combineFile();
	void cldarLstUpdate(const QDate &);
	void cldarTdUpdate(const QDate &);
	int initInfo(const QString &);

	void addjy();
	void addlcj();
	void addlof();
	void addta();

	void copy_jy();
	void copy_lcj();
	void copy_lof();
	void copy_ta();

	void copy_morning();
	void copy_noon();
	void copy_night();

	public slots:
	void copy();
	void copy_other();

	void showJy();
	void showLof();
	void showTa();
	void showLcj();

	void addTbItem();
	void saveTbItem();
	void deleteTbItem();

	void showProgress(int);

	//accept slots
	void get_cfg_item(const QStringList&);

private:
	quint64	salesID;
	QString salesName;
	QMap<QString, QStringList> Info, sendInfo,
		winrarInfo;
	QStringList fPathList, tPathList;
	int	ISize;

	QDateTime local;
	QDateTime lastDay;
	SalesCfg *cfg;
	DefDateTimeEdit *m_DefDateTimeEdit1, *m_DefDateTimeEdit2;
	QProgressDialog *progress;

	QAction *cfgjy_ac, *cfglof_ac,
		*cfgta_ac, *cfglcj_ac;
	QAction *copy_jy_ac, *copy_lof_ac,
		*copy_ta_ac, *copy_lcj_ac;
	QAction *copy_morning_ac, *copy_noon_ac, *copy_night_ac;

	CONTENT m_content = JY;
	QString cfg_name = "";
	QDir m_dir;

	int currentIndex = 0;
	TIME m_time = MORNING;
	QStringList mor_list,noon_list,night_list;

	//初始化信息
	void initTable();
	void updateTable(CONTENT);
	void initOtherInfo(QStringList);
	QString getShortName(const QStringList&);

	//拷贝，读取文件中的某一行
	int countLines(char *filename);
	string readCerLine(char *filename, int line);

};

#endif // TADAILY_H
