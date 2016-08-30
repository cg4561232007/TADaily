#include "tadaily.h"
#include "qpalette.h"
#include "qdir.h"

#include <vector>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <map>

using namespace Ui;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::map;

TaDaily::TaDaily(QWidget *parent)
	: QMainWindow(parent)
{	
	setupUi(this);

	//���ò˵�
	cfgjy_ac = new QAction(QString::fromLocal8Bit("����������"), this);
	cfglcj_ac = new QAction(QString::fromLocal8Bit("��ƽ��˲�����"), this);
	cfglof_ac = new QAction(QString::fromLocal8Bit("lof�й�������"), this);
	cfgta_ac = new QAction(QString::fromLocal8Bit("�Խ�TA�й�������"), this);

	menu->addAction(cfgjy_ac);
	menu->addAction(cfglcj_ac);
	menu->addAction(cfglof_ac);
	menu->addAction(cfgta_ac);

	connect(cfgjy_ac, SIGNAL(triggered()), this, SLOT(showJy()));
	connect(cfglcj_ac, SIGNAL(triggered()), this, SLOT(showLcj()));
	connect(cfglof_ac, SIGNAL(triggered()), this, SLOT(showLof()));
	connect(cfgta_ac, SIGNAL(triggered()), this, SLOT(showTa()));

	//���Ͳ˵�
	copy_jy_ac = new QAction(QString::fromLocal8Bit("����������"), this);
	copy_lof_ac = new QAction(QString::fromLocal8Bit("����lof�й���"), this);
	copy_ta_ac = new QAction(QString::fromLocal8Bit("�����Խ�TA�й���"), this);
	copy_lcj_ac = new QAction(QString::fromLocal8Bit("������ƽ��˲���"), this);

	menu_send->addAction(copy_jy_ac);
	menu_send->addAction(copy_lof_ac);
	menu_send->addAction(copy_ta_ac);
	menu_send->addAction(copy_lcj_ac);

	connect(copy_jy_ac, SIGNAL(triggered()), this, SLOT(copy_jy()));
	connect(copy_lof_ac, SIGNAL(triggered()), this, SLOT(copy_lof()));
	connect(copy_ta_ac, SIGNAL(triggered()), this, SLOT(copy_ta()));
	connect(copy_lcj_ac, SIGNAL(triggered()), this, SLOT(copy_lcj()));

	//�������ݷ��Ͳ˵�
	copy_morning_ac = new QAction(QString::fromLocal8Bit("Ͷ����������	"), this);
	copy_noon_ac = new QAction(QString::fromLocal8Bit("loff��������"), this);
	copy_night_ac = new QAction(QString::fromLocal8Bit("ETF����"), this);

	menu_other->addAction(copy_morning_ac);
	menu_other->addAction(copy_noon_ac);
	menu_other->addAction(copy_night_ac);

	connect(copy_morning_ac, SIGNAL(triggered()), this, SLOT(copy_morning()));
	connect(copy_noon_ac, SIGNAL(triggered()), this, SLOT(copy_noon()));
	connect(copy_night_ac, SIGNAL(triggered()), this, SLOT(copy_night()));
	connect(otherCpBt, SIGNAL(clicked()), this, SLOT(copy_other()));

	//������Ŀ,�޸���Ŀ��ɾ����Ŀ��������Ŀ
	connect(newItemBt, SIGNAL(clicked()), this, SLOT(addTbItem()));
	connect(saveItemBt, SIGNAL(clicked()), this, SLOT(saveTbItem()));
	connect(deleteItemBt, SIGNAL(clicked()), this, SLOT(deleteTbItem()));

	//�ϲ��Ϳ�������
	//connect(comboBox, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(setID(const QString&)));
	//connect(comboBox_2, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(setName(const QString&)));

	local = QDateTime::currentDateTime();
	lastDay = local.addDays(-1);
	if (lastDay.date().dayOfWeek() == 7)
		lastDay = lastDay.addDays(-2);

	QString localTime = local.toString("yyyy - MM - dd");
	timeLb->setText(QString::fromLocal8Bit("����: ")+localTime);

	QFont ft;
	ft.setPointSize(15);
	timeLb->setFont(ft);
	QPalette ple;
	ple.setColor(QPalette::WindowText, Qt::black);
	timeLb->setPalette(ple);

	//�Զ��������ؼ�
	m_DefDateTimeEdit1 = new DefDateTimeEdit(this);
	m_DefDateTimeEdit2 = new DefDateTimeEdit(this);
	connect(m_DefDateTimeEdit1, SIGNAL(update(QDate)), this, SLOT(cldarLstUpdate(QDate)));
	connect(m_DefDateTimeEdit2, SIGNAL(update(QDate)), this, SLOT(cldarTdUpdate(QDate)));
	m_DefDateTimeEdit2->setDateTime(local);
	m_DefDateTimeEdit1->setDateTime(lastDay);
	gHorizonLayout->addWidget(m_DefDateTimeEdit1);
	gHorizonLayout->addWidget(m_DefDateTimeEdit2);

	//Tab
	tabWidget->setTabText(0, QString::fromLocal8Bit("��������"));
	tabWidget->setTabText(1, QString::fromLocal8Bit("������ϸ"));
	tabWidget->setCurrentIndex(0);

	initTable();
}

TaDaily::~TaDaily()
{
	delete m_DefDateTimeEdit1;
	delete m_DefDateTimeEdit2;

}

void TaDaily::initTable()
{
	QStringList headers;
	//headers << QString::fromLocal8Bit("�����ļ�") << QString::fromLocal8Bit("Ŀ���ļ�") << QString::fromLocal8Bit("״̬");
	headers << QString::fromLocal8Bit("������ID") << QString::fromLocal8Bit("����������")
		<< QString::fromLocal8Bit("��֤ͨ��") << QString::fromLocal8Bit("Դ·��") << QString::fromLocal8Bit("Ŀ��·��");
	fileTbWidget->setColumnCount(5);
	fileTbWidget->setRowCount(20);

	fileTbWidget->setHorizontalHeaderLabels(headers);
	int mw = fileTbWidget->horizontalHeader()->width();
	fileTbWidget->horizontalHeader()->setDefaultSectionSize(90);	//260
	fileTbWidget->horizontalHeader()->resizeSection(3, 172);
	fileTbWidget->horizontalHeader()->resizeSection(4, 172);

	fileTbWidget->horizontalHeader()->setStretchLastSection(true);
	fileTbWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	fileTbWidget->verticalHeader()->setVisible(false);
	fileTbWidget->setFrameShape(QFrame::NoFrame);
	fileTbWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
	fileTbWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
	fileTbWidget->setStyleSheet("selection-background-color:lightblue;");
	fileTbWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");

	fileTbWidget->horizontalScrollBar()->setStyleSheet("QScrollBar{background:transparent; height:10px;}"
		"QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
		"QScrollBar::handle:hover{background:gray;}"
		"QScrollBar::sub-line{background:transparent;}"
		"QScrollBar::add-line{background:transparent;}");
	fileTbWidget->verticalScrollBar()->setStyleSheet("QScrollBar{background:transparent; width: 10px;}"
		"QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
		"QScrollBar::handle:hover{background:gray;}"
		"QScrollBar::sub-line{background:transparent;}"
		"QScrollBar::add-line{background:transparent;}");
	fileTbWidget->setAutoScroll(true);

	
	//�����ļ���Tab������
	QStringList otherHeader;
	otherHeader << QString::fromLocal8Bit("�ļ�") << QString::fromLocal8Bit("����Ŀ¼")
		 << QString::fromLocal8Bit("Դ·��") << QString::fromLocal8Bit("Ŀ��·��");
	sendTbWid->setColumnCount(4);
	sendTbWid->setRowCount(20);

	sendTbWid->setHorizontalHeaderLabels(otherHeader);
	sendTbWid->horizontalHeader()->resizeSection(0, 180);
	sendTbWid->horizontalHeader()->resizeSection(1, 100);
	sendTbWid->horizontalHeader()->resizeSection(2, 150);
	sendTbWid->horizontalHeader()->resizeSection(3, 150);
	//sendTbWid->setEditTriggers(QAbstractItemView::NoEditTriggers);
	//sendTbWid->setShowGrid(false);

	sendTbWid->horizontalHeader()->setStretchLastSection(true);
	sendTbWid->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	sendTbWid->verticalHeader()->setVisible(false);
	sendTbWid->setFrameShape(QFrame::NoFrame);
	sendTbWid->setSelectionBehavior(QAbstractItemView::SelectRows);
	sendTbWid->setSelectionMode(QAbstractItemView::ExtendedSelection);
	sendTbWid->setStyleSheet("selection-background-color:lightblue;");
	sendTbWid->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");

	sendTbWid->horizontalScrollBar()->setStyleSheet("QScrollBar{background:transparent; height:10px;}"
		"QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
		"QScrollBar::handle:hover{background:gray;}"
		"QScrollBar::sub-line{background:transparent;}"
		"QScrollBar::add-line{background:transparent;}");
	sendTbWid->verticalScrollBar()->setStyleSheet("QScrollBar{background:transparent; width: 10px;}"
		"QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
		"QScrollBar::handle:hover{background:gray;}"
		"QScrollBar::sub-line{background:transparent;}"
		"QScrollBar::add-line{background:transparent;}");
	sendTbWid->setAutoScroll(true);
}


/********************** Table��ʾ�����ļ�����ϸ��Ϣ *********************/
void TaDaily::showJy()
{
	tabWidget->setCurrentIndex(0);
	updateTable(JY);
	m_content = JY;
}

void TaDaily::showLof()
{
	tabWidget->setCurrentIndex(0);
	updateTable(LOF);
	m_content = LOF;
}

void TaDaily::showTa()
{
	tabWidget->setCurrentIndex(0);
	updateTable(TA);
	m_content = TA;
}

void TaDaily::showLcj()
{
	tabWidget->setCurrentIndex(0);
	updateTable(LCJ);
	m_content = LCJ;
}

/*************************** ���±����� *****************************/
void TaDaily::updateTable(CONTENT content)
{
	
	//����֮ǰ�Ƚ�֮ǰ��ʾ�����ݵ����
	fileTbWidget->clearContents();
	fileTbWidget->clear();

	QStringList hd;
	switch (content)
	{
	case JY:
		cfg_name = "jyfs.ini";
		hd << QString::fromLocal8Bit("������ID") << QString::fromLocal8Bit("����������")
			<< QString::fromLocal8Bit("��֤ͨ��") << QString::fromLocal8Bit("Դ·��") << QString::fromLocal8Bit("Ŀ��·��");
		fileTbWidget->setColumnCount(5);
		fileTbWidget->setHorizontalHeaderLabels(hd);
		break;
	case LOF:
		cfg_name = "tghloffs.ini";
		hd << QString::fromLocal8Bit("lof�й���ID") << QString::fromLocal8Bit("lof�й�������")
			<< QString::fromLocal8Bit("��֤ͨ��") << QString::fromLocal8Bit("Դ·��") << QString::fromLocal8Bit("Ŀ��·��");
		fileTbWidget->setColumnCount(5);
		fileTbWidget->setHorizontalHeaderLabels(hd);
		break;
	case TA:
		cfg_name = "tghtafs.ini";
		hd << QString::fromLocal8Bit("TA�й���ID") << QString::fromLocal8Bit("TA�й�������")
			<< QString::fromLocal8Bit("��֤ͨ��") << QString::fromLocal8Bit("Դ·��") << QString::fromLocal8Bit("Ŀ��·��");
		fileTbWidget->setColumnCount(5);
		fileTbWidget->setHorizontalHeaderLabels(hd);
		break;
	case LCJ:
		cfg_name = "lcjtb.ini";
		hd << QString::fromLocal8Bit("��ƽ�������ID") << QString::fromLocal8Bit("����������")
			<< QString::fromLocal8Bit("��֤ͨ��") << QString::fromLocal8Bit("Դ·��") << QString::fromLocal8Bit("Ŀ��·��");
		fileTbWidget->setColumnCount(5);
		fileTbWidget->setHorizontalHeaderLabels(hd);
		break;
	default:
		break;
	}

	//��ini�ļ���table����ʾ��Ϣ
	QDir dir;
	dir.setCurrent(QCoreApplication::applicationDirPath());
	QFile file;
	file.setFileName(dir.filePath(cfg_name));
	QTextStream istream(&file);

	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QString readLine;
		QStringList splist;
		int row = 0;
		while (istream.readLineInto(&readLine))
		{
			if (row >= fileTbWidget->rowCount())
				fileTbWidget->insertRow(row);

			splist = readLine.split(";");
			for (int j = 0; j < splist.size(); j++)
				fileTbWidget->setItem(row, j, new QTableWidgetItem(splist[j]));
			++row;
		}

		file.close();
		currentIndex = row - 1;
	}

	fileTbWidget->sortItems(0,Qt::AscendingOrder);
	
}

QString TaDaily::getShortName(const QStringList &qs)
{
	QString tmps;
	for (const QString s : qs){
		int index = s.lastIndexOf("/");
		tmps += s.right(s.size() - index - 1) + QString(";");
	}
	return tmps;
}

/*
	���������е��ļ����п�������
	����ʹ�ò������ļ����󣬻���������
	io�����׳��쳣
*/
void TaDaily::copy()
{

	//���㷢���ļ����ѵ�ʱ��
	clock_t time_start = clock();
	clock_t time_end;
	int elipse = 0;

	//���������ļ�
	if (winrarInfo.size() != 0)
	{
		int i = 0;
		for (auto iter = winrarInfo.begin(); iter != winrarInfo.end(); iter++)
		{
			bool ok = false;
			if (!m_dir.exists(iter.value()[3]))
			{
				ok = m_dir.mkdir(iter.value()[3]);
				if (ok)
					qDebug() << " CREATING FOLDER SUCCEED ";
				else
				{
					qDebug() << " TO PAHT NOT EXISTS :" << iter.value()[3];
					logBrowser->append(QString("TO PATH NOT EXISTS:\n%1").arg(iter.value()[3]));
				}
			}

			if (m_dir.exists(iter.value()[2]) && m_dir.exists(iter.value()[3]))
			{
				m_dir.setCurrent(iter.value()[2]);
				QStringList allfiles, ffiles;
				allfiles = m_dir.entryList(QDir::Files);
				for (QString q : allfiles)
				{
					if (q.contains("OFD") || q.contains("OFI")
						|| q.contains("OFK") || q.contains("OFS")
						|| q.contains("OFG"))
						ffiles.push_back(iter.value()[2] + "\\" + q);
				}
				char sys[200];
				string cmd = string("winrar a ") + iter.value()[3].toStdString() + string("\\")
					+ iter.key().toStdString() +string(".rar ") + iter.value()[2].toStdString() + string("\\*.txt");
				sprintf(sys, cmd.c_str());
				system(sys);
				//system("winrar a D:\\kfjj\\send\\20160812\\Confirm\\k0216ccb.rar W:\\output\\20160812\\005\\Confirm\\*.txt");
				qDebug() << QString("COPYING %1 of %2 FILES").arg(i + 1).arg(winrarInfo.size());

				string okRarName;
				okRarName = iter.value()[3].toStdString() + string("\\") + iter.key().toStdString() + string(".rar.OK");
				ofstream okrs;
				okrs.open(okRarName.c_str(), std::ios::binary);
				if (!okrs.is_open())
				{
					qDebug() << "WRITTING .OK FILES ERROR";
					continue;
				}
				okrs.close();
				i++;
			}
			else
				logBrowser->append(QString("FROM PATH NOT EXISTS:\n%1").arg(iter.value()[2]));

			if (!m_dir.exists(iter.value()[3]))
				logBrowser->append(QString("TO PATH NOT EXISTS:\n%1").arg(iter.value()[3]));
		}
	}
	
	//���������ļ�
	int fSize = fPathList.size();
	int tSize = tPathList.size();
	if (fSize != tSize)
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("������Ϣ����"),
			QString::fromLocal8Bit("Դ·����Ŀ��·����Ŀ��һ��"), QMessageBox::Ok);
		return;
	}
	if (fSize == 0 && winrarInfo.size() == 0)
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("����"),
			QString::fromLocal8Bit("������ϢΪ��"), QMessageBox::Ok);
		return;
	}

	if (fSize == 0)
		return;

	vector<string> fVec, tVec;
	QDir dir1,dir2;
	bool flag = false;
	for (int i = 0; i < fSize;i++)
	{
		//��������ļ�·���Ƿ���������Ϣһ��
		if (dir1.exists(fPathList[i])){
			dir1.setCurrent(fPathList[i]);
		}
		else{
			qDebug() << " FROM PATH NOT EXISTS:" << fPathList[i];
			logBrowser->append(QString("FROM PATH NOT EXISTS:\n%1").arg(fPathList[i]));
			continue;
		}

		//�ж����·���Ƿ���ڣ����򴴽�
		if (!dir2.exists(tPathList[i]))
		{
			bool ok = dir2.mkdir(tPathList[i]);
			if (ok)
				qDebug() << " CREATING FOLDER SUCCEED ";
			else
			{
				qDebug() << " TO PAHT NOT EXISTS :" << tPathList[i];
				logBrowser->append(QString("TO PATH NOT EXISTS:\n%1").arg(tPathList[i]));
			}
		}

		//��ȡ����·���е������ļ�
		//ֻ����files���ض����ļ�OFD��
		QStringList allfiles, ffiles;
		allfiles = dir1.entryList(QDir::Files);
		for (QString q : allfiles)
		{
			if (q.contains("OFD") || q.contains("OFI")
				|| q.contains("OFK") || q.contains("OFS")
				|| q.contains("OFG"))
				ffiles.push_back(q);
		}

		QString abToName, abFromName;
		for (QString name : ffiles)
		{
			abFromName = fPathList[i] + "\\" + name;
			fVec.push_back(abFromName.toStdString());
			abToName = tPathList[i] + "\\" + name ;
			tVec.push_back(abToName.toStdString());
		}
	}

	//�Բ�ͬ�������ļ���������ļ����п���
	int fVSize = fVec.size();
	showProgress(fVSize);
	totalLb->setText(QString::number(fVSize));
	ifstream in;
	ofstream out;
	const char *spath = '\0',*rpath = '\0';

	for (int i = 0; i < fVSize; i++)
	{
		spath = fVec[i].c_str();
		rpath = tVec[i].c_str();
		in.open(spath, std::ios::binary);
		out.open(rpath, std::ios::binary);
		if (!in.is_open())
		{
			qDebug() << " READING FILES ERROR ";
			logBrowser->append(QString("READING FILE ERROR IN:\n%1").arg(QString::fromStdString(fVec[i])));
			continue;
		}
		if (!out.is_open())
		{
			qDebug() << " WRITTING FILES ERROR ";
			logBrowser->append(QString("WRITTING FILE ERROR IN:\n%1").arg(QString::fromStdString(tVec[i])));
			continue;
		}

		out << in.rdbuf();
		in.close();
		out.close();
		qDebug() << QString("COPYING %1 of %2 FILES").arg(i + 1).arg(fVSize);
		progress->setValue(i);
		sendLb->setText(QString::number(i + 1));

	}

	//��鿽��Ŀ¼������.OK�ļ�
	for (int i = 0; i < fSize; i++)
	{
		//����.OK�ļ��ٴμ��Ŀ¼�Ƿ����
		if (!dir1.exists(tPathList[i]))
			continue;

		dir1.setCurrent(fPathList[i]);
		QStringList allfiles = dir1.entryList(QDir::Files);
		QStringList tfiles;
		for (QString q : allfiles)
		{
			if (q.contains("OFD") || q.contains("OFI")
				|| q.contains("OFK") || q.contains("OFS")
				|| q.contains("OFG"))
				tfiles.push_back(q);
		}

		string okToName;
		const char *okpath = '\0';
		ofstream oks;
		for (QString ns : tfiles)
		{
			okToName = QString(tPathList[i] + "\\" + ns + ".OK").toStdString();
			okpath = okToName.c_str();
			oks.open(okpath, std::ios::binary);
			if (!oks.is_open())
			{
				qDebug() << "WRITTING .OK FILES ERROR";
				continue;
			}
			oks.close();
		}
	}

	//��ʾʱ������
	time_end = clock();
	elipse = (int)(time_end - time_start) / 1000.0;
	costLb->setText(QString::number(elipse));

	//����ļ��б��ֹ�´��ظ�����
	fPathList.clear();
	tPathList.clear();
	Info.clear();
	
}

//��������ʾ�Ի���
void TaDaily::showProgress(int num)
{
	progress = new QProgressDialog(this);
	progress->setLabelText(tr("copy processing."));
	progress->setWindowTitle(QString::fromLocal8Bit("��������"));
	progress->setCancelButtonText(tr("Cancel"));
	progress->setRange(0, num-1);
	progress->setValue(0);
	progress->setModal(true);
	progress->show();

	//���ȡ��ֹͣ����

}

//��ʼ��������Ϣ
int TaDaily::initInfo(const QString &fn)
{

	//ʹ��Qt IO���ж��ļ����������ı�
	QDir dir;
	QStringList filters;
	filters << ".txt";
	dir.setNameFilters(filters);
	dir.setCurrent(QCoreApplication::applicationDirPath());

	QFile file;
	if (!dir.exists(fn))
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�����ļ�������"),
			QMessageBox::Ok);
		return -1;
	}

	file.setFileName(dir.filePath(fn));
	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream inStream(&file);
		QString readLine;
		QStringList splist;
		while (inStream.readLineInto(&readLine))
		{
			splist = readLine.split(";");
			QStringList otherInfo;
			for (int j = 1; j < splist.size(); j++)
				otherInfo.push_back(splist[j]);

			if (splist[1].contains("winrar"))
			{
				winrarInfo.insert(splist[0], otherInfo);
				continue;
			}
			Info.insert(splist[0], otherInfo);
			readLine.clear();
		}
		file.close();
	}
	else
	{
		qDebug() << "Opening file error!" << endl;
		return -1;
	}

	//����װ��QStringList��
	QStringList ID, nameList;
	for (QMap<QString, QStringList>::const_iterator iter = Info.constBegin(); iter != Info.constEnd(); iter++)
	{
		//������������Ϣ��СΪ4
		if (iter.value().size() != 4)
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("���ø�ʽ����"),
				QMessageBox::Ok);
			return -1;
		}

		ID.append(iter.key());
		nameList.append(iter.value()[0]);
	}

	ISize = Info.size();

	QString fp, tp;
	QDateTime specialDay = local;
	if (fn == "lcjtb.ini")
		specialDay = lastDay;
	QString day1 = specialDay.toString("yyyyMMdd");					//local.toString("yyyyMMdd")
	QString day2 = local.toString("yyyyMMdd");						//localָ���칤����

	//������ʽʶ��ͨ��������滻�ɵ�������local.toString("yyyyMMdd")
	QString pattern = "[a-zA-Z]{4}[a-zA-Z]{2}[a-zA-Z]{2}";
	QRegExp rx(pattern);

	for (int i = 0; i < ISize; i++)
	{
		fp = Info[ID[i]][2].replace(rx, day1);
		tp = Info[ID[i]][3].replace(rx, day2);
		fPathList.push_back(fp);
		tPathList.push_back(tp);
	}
	if (winrarInfo.size() != 0)
	{
		for (auto iter = winrarInfo.begin(); iter != winrarInfo.end(); iter++)
		{
			iter.value()[2].replace(rx, day1);
			iter.value()[3].replace(rx, day2);
		}
	}
	
	logBrowser->append(QString("FROM DATE: %1").arg(day1));
	logBrowser->append(QString("TO DATE: %1").arg(day2));
	return 0;
}

void TaDaily::closeEvent(QCloseEvent *event)
{
	this->close();
}

void TaDaily::fromAdd()
{
	QFileDialog *filedialog = new QFileDialog(this);
	filedialog->setWindowTitle(tr("FROM OPTIONS"));
	filedialog->setFileMode(QFileDialog::Directory);

	filedialog->setOption(QFileDialog::DontUseNativeDialog, true);
	QListView *l = filedialog->findChild<QListView *>("ListView");
	if (l)
	{
		l->setSelectionMode(QAbstractItemView::MultiSelection);
	}
	QTreeView *t = filedialog->findChild<QTreeView *>();
	filedialog->setFilter(QDir::Dirs);

	QString fromName;
	if (filedialog->exec() == QDialog::Accepted)
		fromName = filedialog->selectedFiles()[0];
	else
		return;
}

void TaDaily::toAdd()
{
	QFileDialog *filedialog = new QFileDialog(this);
	filedialog->setWindowTitle(tr("FEOM OPTIONS"));
	filedialog->setFileMode(QFileDialog::Directory);
	filedialog->setOption(QFileDialog::DontUseNativeDialog, true);

	QListView *l = filedialog->findChild<QListView *>("ListView");
	if (l)
	{
		l->setSelectionMode(QAbstractItemView::MultiSelection);
	}
	QTreeView *t = filedialog->findChild<QTreeView *>();
	filedialog->setFilter(QDir::Dirs);

	QString toName;
	if (filedialog->exec() == QDialog::Accepted)
		toName = filedialog->selectedFiles()[0];
	else
		return;
}

//����������ѡ���л�ϵͳʱ��
void TaDaily::cldarTdUpdate(const QDate& date)
{
	local = QDateTime(date);
	timeLb->setText(QString::fromLocal8Bit("����: ") + local.toString("yyyy - MM - dd"));
}

void TaDaily::cldarLstUpdate(const QDate& date)
{
	lastDay = QDateTime(date);
}

/**
	��ӽ���ȷ����Ϣ�Ľӿ�
	����ȷ������
*/
void TaDaily::addjy()
{
	cfg = new SalesCfg("jyfs.ini");
	connect(cfg, SIGNAL(add_tb_item(QStringList)), this, SLOT(get_cfg_item(QStringList)));
	cfg->show();
	cfg->setWindowTitle(QString::fromLocal8Bit("����ȷ������"));
	QStringList info;
	info.push_back(QString::fromLocal8Bit("������ID"));
	info.push_back(QString::fromLocal8Bit("����������"));
	info.push_back(QString::fromLocal8Bit("��֤ͨ��"));
	cfg->setInfo(info);
	currentIndex++;
}

/**
	�����ƽ���Ϣ�Ľӿ�
*/
void TaDaily::addlcj()
{
	cfg = new SalesCfg("lcjtb.ini");
	connect(cfg, SIGNAL(add_tb_item(QStringList)), this, SLOT(get_cfg_item(QStringList)));
	cfg->show();
	cfg->setWindowTitle(QString::fromLocal8Bit("��ƽ�����"));
	QStringList info;
	info.push_back(QString::fromLocal8Bit("������ID"));
	info.push_back(QString::fromLocal8Bit("����������"));
	info.push_back(QString::fromLocal8Bit("��֤ͨ��"));
	cfg->setInfo(info);
	currentIndex++;
}

/**
	���lof�й�����Ϣ�Ľӿ�
*/
void TaDaily::addlof()
{
	cfg = new SalesCfg("tghloffs.ini");
	connect(cfg, SIGNAL(add_tb_item(QStringList)), this, SLOT(get_cfg_item(QStringList)));
	cfg->show();
	cfg->setWindowTitle(QString::fromLocal8Bit("lof�й�������"));
	QStringList info;
	info.push_back(QString::fromLocal8Bit("LOF�й���ID"));
	info.push_back(QString::fromLocal8Bit("LOF�й�������"));
	info.push_back(QString::fromLocal8Bit("��֤ͨ��"));
	cfg->setInfo(info);
	currentIndex++;
}

/**
	����Խ�ta�й�����Ϣ�Ľӿ�
*/
void TaDaily::addta()
{
	cfg = new SalesCfg("tghtafs.ini");
	connect(cfg, SIGNAL(add_tb_item(QStringList)), this, SLOT(get_cfg_item(QStringList)));
	cfg->show();
	cfg->setWindowTitle(QString::fromLocal8Bit("�Խ�TA�й�������"));
	QStringList info;
	info.push_back(QString::fromLocal8Bit("�Խ�TA�й���ID"));
	info.push_back(QString::fromLocal8Bit("�Խ�TA�й�������"));
	info.push_back(QString::fromLocal8Bit("��֤ͨ��"));
	cfg->setInfo(info);
	currentIndex++;
}

//Table��������Ŀ
void TaDaily::addTbItem()
{
	switch (m_content)
	{
	case JY:
		addjy();
		cfg_name = "jyfs.ini";
		break;
	case LOF:
		addlof();
		cfg_name = "tghloffs.ini";
		break;
	case TA:
		addta();
		cfg_name = "tghtafs.ini";
		break;
	case LCJ:
		addlcj();
		cfg_name = "lcjtb.ini";
		break;
	default:
		break;
	}
	fileTbWidget->insertRow(currentIndex);
}

//Table�����һ��
void TaDaily::get_cfg_item(const QStringList& cfg_item)
{
	for (int j = 0; j < 5; j++)
		fileTbWidget->setItem(currentIndex, j, new QTableWidgetItem(cfg_item[j]));
}

//Table��������Ŀ
void TaDaily::saveTbItem()
{
	m_dir.setCurrent(QCoreApplication::applicationDirPath());
	if (!m_dir.exists(cfg_name))
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�����ļ�������"),
			QMessageBox::Ok);
		return;
	}

	QFile file;
	file.setFileName(m_dir.filePath(cfg_name));
	QTextStream os(&file);
	QString id, name, ser, fpath, tpath;
	if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
	{
		file.resize(0);
		// row < currentIndex
		for (int row = 0; row < currentIndex + 1; row++)
		{
			if (fileTbWidget->item(row, 0) != NULL)
			{
				id = fileTbWidget->item(row, 0)->text();
				name = fileTbWidget->item(row, 1)->text();
				ser = fileTbWidget->item(row, 2)->text();
				fpath = fileTbWidget->item(row, 3)->text();
				tpath = fileTbWidget->item(row, 4)->text();
				
				QString args = QString("%1;%2;%3;%4;%5\n")
					.arg(id).arg(name).arg(ser).arg(fpath).arg(tpath);
				os << args;
			}	
		}
		file.close();
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"),
			QString::fromLocal8Bit("����ɹ�"), QMessageBox::Ok);
	}
}

//Tableɾ����Ŀ
void TaDaily::deleteTbItem()
{
	int rowIndex = fileTbWidget->currentRow();
	if (rowIndex != -1)
		fileTbWidget->removeRow(rowIndex);
	currentIndex--;
	saveTbItem();
}

/************��������*************/
/**
	���������̽���ȷ��
*/
void TaDaily::copy_jy()
{
	logBrowser->clear();
	if (0 == initInfo("jyfs.ini"))
		copy();
}

/**
	��������lof
*/
void TaDaily::copy_lof()
{
	logBrowser->clear();
	if (0 == initInfo("tghloffs.ini"))
		copy();
}

/**
	�����Խ�ta
*/
void TaDaily::copy_ta()
{
	logBrowser->clear();
	if (0 == initInfo("tghtafs.ini"))
		copy();
}

/**
	������ƽ��˲�
*/
void TaDaily::copy_lcj()
{
	logBrowser->clear();
	if (0 == initInfo("lcjtb.ini"))
		copy();
}

void TaDaily::initOtherInfo(QStringList sl)
{
	m_dir.setCurrent(QCoreApplication::applicationDirPath());
	QFile file;
	QString	fn = "other.ini";
	if (!m_dir.exists("other.ini"))
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�����ļ�������"),
			QMessageBox::Ok);
	}

	//����������Ҫ���͵��ļ�������
	file.setFileName(m_dir.filePath(fn));
	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream inStream(&file);
		QString readLine;
		QStringList flist;
		QString from_path, to_path, itemName;
		int cnt = 0;
		while (inStream.readLineInto(&readLine))
		{
			if (readLine.contains("[") || readLine.contains("END"))
			{
				if (cnt != 0)
				{
					sendInfo.insert(itemName, flist);
				}
				cnt++;
				int pos1 = readLine.indexOf("[");
				int pos2 = readLine.indexOf("]");
				itemName = readLine.mid(pos1+1, pos2 - pos1-1);
				flist.clear();
				continue;
			}
			if (readLine.isEmpty())
				continue;

			if (readLine.contains("from"))
			{
				from_path = readLine.mid(readLine.indexOf("=")+1);
				flist.push_back(from_path);
				continue;
			}
			if (readLine.contains("to"))
			{
				to_path = readLine.mid(readLine.indexOf("=") + 1);
				flist.push_back(to_path);
				continue;
			}
			flist.push_back(readLine.mid(readLine.indexOf(":") + 1));
		}
		file.close();
	}
	else 
	{
		qDebug() << "Opening file error!" << endl;
	}

	//��ʾϸ����table��
	int row = 0;
	int nfiles = 0;
	for (auto it = sl.begin(); it != sl.end(); ++it)
	{
		nfiles += sendInfo[*it].size() - 2;
	}

	for (auto it = sl.begin(); it != sl.end(); ++it)
	{
		int sz = sendInfo[*it].size();
		for (int i = 0; i < sz - 2; i++)
		{
			if (row >= sendTbWid->rowCount())
				sendTbWid->insertRow(row);

			sendTbWid->setItem(row, 0, new QTableWidgetItem(QIcon("Resources/wrong.png"), sendInfo[*it][i + 2]));
			sendTbWid->setItem(row, 1, new QTableWidgetItem(*it));
			sendTbWid->setItem(row, 2, new QTableWidgetItem(sendInfo[*it][0]));
			sendTbWid->setItem(row, 3, new QTableWidgetItem(sendInfo[*it][1]));
			row++;
		}
	}

}

/**
	�������ݷ���:
		1.TA��ƽӿ�_����
		2.TA����ӿ�_����
		3.TAͶ�ʽ��׽ӿ�
		4.TA��ϴǮ�ӿ�
		5.LOF����ȷ��
*/
void TaDaily::copy_morning()
{
	tabWidget->setCurrentIndex(1);
	mor_list.clear();
	mor_list << "TA_KJ_JJ" << "TA_QS_JJ" << "TA_TZJY"
		<< "TA_FXQ" << "LOF_JYQR";
	sendTbWid->clear();
	sendTbWid->clearContents();
	initOtherInfo(mor_list);
	m_time = MORNING;
	//copy_other(mor_list);
}

/**
	�������ݷ���:
		1.LOFTA��ϴǮ�ӿ�
		2.LOFTA��ƽӿ�_����
		3.LOFTA����ӿ�_����
*/
void TaDaily::copy_noon()
{
	tabWidget->setCurrentIndex(1);
	noon_list.clear();
	noon_list << "LOFTA_FXQ" << "LOFTA_KJ_JJ" << "LOFTA_TZJY"
		<< "LOFTA_QS_JJ";
	sendTbWid->clear();
	sendTbWid->clearContents();
	initOtherInfo(noon_list);
	m_time = NOON;
	//copy_other(noon_list);
}

/**
	�������ݷ���:
		1.ETF300HB��ƽӿ�
		2.ETF300HBͶ�ʽӿ�
*/
void TaDaily::copy_night()
{
	tabWidget->setCurrentIndex(1);
	night_list.clear();
	night_list << "ETF300HB_KJ" << "ETF300HB_TZ";
	sendTbWid->clear();
	sendTbWid->clearContents();
	initOtherInfo(night_list);
	m_time = NIGHT;
	//copy_other(night_list);
}

void TaDaily::copy_other()
{
	QStringList time_list;
	switch (m_time)
	{
	case MORNING:
		time_list = mor_list;
		break;
	case NOON:
		time_list = noon_list;
		break;
	case NIGHT:
		time_list = night_list;
		break;
	default:
		break;
	}

	//������ʽ�滻yyyymmdd
	QString pattern = "[a-z]{4}[a-z]{2}[a-z]{2}";
	QRegExp rx(pattern);

	//��������
	QString today = local.toString("yyyyMMdd");							//localָ���칤����

	vector<string> ok_vec;
	map<string,vector<string>> ok_f_name,ok_t_name;
	vector<string> f_mor_vec, t_mor_vec;
	int file_nums = 0;

	for (QMap<QString, QStringList> ::const_iterator it = sendInfo.cbegin(); it != sendInfo.cend(); it++)
	{
		if (time_list.contains(it.key()))
		{
			QString fdir = it.value()[0];
			QString tdir = it.value()[1];
			fdir.replace(rx, today);
			tdir.replace(rx, today);

			if (!m_dir.exists(fdir)){
				qDebug() << "FROM DIR NOT EXISTS " << it.value()[0];
				continue;
			}
			if (!m_dir.exists(tdir)){
				qDebug() << "TO DIR NOT EXISTS " << it.value()[1];
				continue;
			}
			qDebug() << it.key();

			for (int j = 2; j < it.value().size(); j++){
				QString abfname = fdir + "\\" + it.value()[j];
				QString abtname = tdir + "\\" + it.value()[j];
				f_mor_vec.push_back(abfname.toStdString());
				t_mor_vec.push_back(abtname.toStdString());
				++file_nums;
			}

			ok_f_name[it.key().toStdString()] = f_mor_vec;
			ok_t_name[it.key().toStdString()] = t_mor_vec;
			f_mor_vec.clear();
			t_mor_vec.clear();
		}
	}

	ifstream in;
	ofstream out;
	const char *f_path = '\0', *t_path = '\0';
	int num = 0;

	for (auto fmt = ok_f_name.begin(),tmt =ok_t_name.begin();
		fmt!= ok_f_name.end(),tmt!=ok_t_name.end(); ++fmt,++tmt)
	{
		for (auto fvt = fmt->second.begin(),tvt = tmt->second.begin(); 
			fvt != fmt->second.end(),tvt!=tmt->second.end(); ++fvt,++tvt)
		{

			f_path = (*fvt).c_str();
			t_path = (*tvt).c_str();
			in.open(f_path, std::ios::binary);
			out.open(t_path, std::ios::binary);

			if (!in.is_open())
			{
				qDebug() << " MISSING FILES " << QString(f_path);
				continue;
			}
			if (!out.is_open())
			{
				qDebug() << " WRITTING FILES ERROR ";
				continue;
			}

			int p1 = (*fvt).find_last_of('\\');
			int p2 = (*tvt).find_last_of('\\');
			ok_vec.push_back((*tvt).substr(0, p2 + 1) + (*fvt).substr(p1 + 1));
			out << in.rdbuf();
			in.close();
			out.close();
			qDebug() << QString("COPYING %1 of %2 FILES").arg(num + 1).arg(file_nums);
			num++;
		}
	}

	//��鿽��Ŀ¼������.OK�ļ�
	for (int i = 0; i < ok_vec.size(); i++)
	{
		string okToName;
		const char *okpath = '\0';
		ofstream oks;
		okToName = ok_vec[i] + ".OK";
		okpath = okToName.c_str();
		oks.open(okpath, std::ios::binary);
		if (!oks.is_open())
		{
			qDebug() << "WRITTING .OK FILES ERROR";
			continue;
		}
		oks.close();
	}

	//����Table����״̬
	string tb_content, tb_class;
	bool flag = false;
	for (int col = 0, rw = 0; rw < sendTbWid->rowCount(); rw++)
	{
		tb_content = sendTbWid->item(rw, col)->text().toStdString();
		tb_class = sendTbWid->item(rw, 1)->text().toStdString();
		auto m_end = ok_f_name.cend();

		flag = false;
		for (auto iter1 = ok_f_name.begin(); iter1 != m_end; ++iter1)
		{
			if (flag)
				break;
			if (iter1->first == tb_class)
			{
				auto iter2 = iter1->second.begin();
				while (iter2!=iter1->second.end())
				{
					int last = (*iter2).find_last_of('\\');
					if ((*iter2).substr(last + 1) == tb_content)
					{
						sendTbWid->setItem(rw, col, new QTableWidgetItem(QIcon("Resources/correct.png"),
							QString::fromStdString(tb_content)));
						flag = true;
						break;
					}
					++iter2;
				}
			}
		}
	}

	sendTbWid->sortItems(0, Qt::AscendingOrder);
}

/**
	�ϲ�ҵ���ļ�
*/
void TaDaily::combineFile()
{

}

//�����ļ�������
int TaDaily::countLines(char *filename)
{
	ifstream ReadFile;
	int n = 0;
	string tmp;
	ReadFile.open(filename, std::ios::in);//ios::in ��ʾ��ֻ���ķ�ʽ��ȡ�ļ�
	if (ReadFile.fail())//�ļ���ʧ��:����0
	{
		return 0;
	}
	else//�ļ�����
	{
		while (getline(ReadFile, tmp, '\n'))
		{
			n++;
		}
		ReadFile.close();
		return n;
	}
}

//��ȡĳһ��
string TaDaily::readCerLine(char *filename, int line)
{
	int lines, i = 0;
	string temp;
	std::fstream file;
	file.open(filename, std::ios::in);
	lines = countLines(filename);

	if (line <= 0)
	{
		return "Error 1: �������󣬲���Ϊ0������";
	}
	if (file.fail())
	{
		return "Error 2: �ļ������ڡ�";
	}
	if (line>lines)
	{
		return "Error 3: ���������ļ����ȡ�";
	}
	while (getline(file, temp) && i<line - 1)
	{
		i++;
	}
	file.close();
	return temp;
}
