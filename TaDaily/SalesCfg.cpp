#include "salescfg.h"
#include "qboxlayout.h"
#include "qdebug.h"

#include <initializer_list>

using std::initializer_list;

SalesCfg::SalesCfg(QString cfg_name,QWidget *parent) 
: QWidget(parent), m_cfg_name(cfg_name)
{
	setupUi(this);

	connect(toBt, SIGNAL(clicked()), this, SLOT(fromAdd()));
	connect(toBt_2, SIGNAL(clicked()), this, SLOT(toAdd()));
	connect(configueBt, SIGNAL(clicked()), this, SLOT(configue()));
}

SalesCfg::~SalesCfg()
{

}

void SalesCfg::configue()
{
	id = lineEdit->text();
	name = lineEdit_2->text();
	ser = lineEdit_3->text();
	fpath= lineTo->text();
	tpath = lineTo_2->text();
	
	if (name.isEmpty() || id.isEmpty() || ser.isEmpty())
		errorLb->setText(QString::fromLocal8Bit("��Ϣ������"));
	else if (id.size() > 5)
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("ID����"), QString::fromLocal8Bit("���Ȳ��ܳ���5"),
			QMessageBox::Ok);
	}

	else
	{
		QDir dir;
		QStringList filters;
		filters << ".txt";
		dir.setNameFilters(filters);
		dir.setCurrent(QCoreApplication::applicationDirPath());
		QFile file;
		QMap<QString, QStringList> Info;
		file.setFileName(dir.filePath(m_cfg_name));

		QTextStream ostream(&file);
		QTextStream istream(&file);
		bool rpt = false;
		if (file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			//����Ƿ����ظ��ģ����ظ��ľ͸���
			QString readLine;
			QStringList splist;

			while (istream.readLineInto(&readLine))
			{
				splist = readLine.split(";");
				QStringList otherInfo;
				for (int j = 1; j < splist.size(); j++)
					otherInfo.push_back(splist[j]);
				if (id != splist[0])
				{
					Info.insert(splist[0], otherInfo);
				}
				else
				{
					rpt = true;
					QStringList tmp;
					tmp << name << ser << fpath << tpath;
					Info.insert(id, tmp);
				}
				readLine.clear();
			}
			file.close();
		}

		//д���µ���Ϣ,���������
		if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
		{
			if (!rpt)
			{
				QString args = QString("%1;%2;%3;%4;%5\n")
					.arg(id).arg(name).arg(ser).arg(fpath).arg(tpath);
				ostream << args;
				emit add_tb_item(QStringList() << id << name << ser << fpath << tpath);
			}
			else
			{
				file.resize(0);
				for (QMap<QString, QStringList>::const_iterator iter = Info.constBegin(); iter != Info.constEnd(); iter++)
				{
					ostream << QString("%1;%2;%3;%4;%5\n")
						.arg(iter.key()).arg(iter.value()[0]).arg(iter.value()[1]).arg(iter.value()[2]).arg(iter.value()[3]);				}
				file.close();
			}
		}	
		this->close();
	}
}

/**
	ѡ���������ļ���·��
*/
void SalesCfg::fromAdd()
{
	QFileDialog *filedialog = new QFileDialog(this);
	filedialog->setWindowTitle(tr("FROM OPTIONS"));
	filedialog->setFileMode(QFileDialog::Directory);

	filedialog->setOption(QFileDialog::DontUseNativeDialog, true);
	QListView *l = filedialog->findChild<QListView *>("ListView");
	if (l) {
		l->setSelectionMode(QAbstractItemView::MultiSelection);
	}
	QTreeView *t = filedialog->findChild<QTreeView *>();
	filedialog->setFilter(QDir::Dirs);

	QString fromName;
	if (filedialog->exec() == QDialog::Accepted){
		fromName = filedialog->selectedFiles()[0];
		int nSize = fromName.size();
		if (nSize == 0)
			return;
	}
	else
		return;

	lineTo->setText(fromName);
}

void SalesCfg::toAdd()
{
	QFileDialog *filedialog = new QFileDialog(this);
	filedialog->setWindowTitle(tr("FROM OPTIONS"));
	filedialog->setFileMode(QFileDialog::Directory);

	filedialog->setOption(QFileDialog::DontUseNativeDialog, true);
	QListView *l = filedialog->findChild<QListView *>("ListView");
	if (l) {
		l->setSelectionMode(QAbstractItemView::MultiSelection);
	}
	QTreeView *t = filedialog->findChild<QTreeView *>();
	filedialog->setFilter(QDir::Dirs);

	QString toName;
	if (filedialog->exec() == QDialog::Accepted){
		toName = filedialog->selectedFiles()[0];
		int nSize = toName.size();
		if (nSize == 0)
			return;
	}
	else
		return;

	lineTo_2->setText(toName);
}

void SalesCfg::setInfo(const QStringList& info)
{
	if (info.size() == 3)
	{
		label_id->setText(info[0]);
		label_name->setText(info[1]);
		label_ser->setText(info[2]);
	}
}

/***
*�ж�һ���ַ����Ƿ�Ϊ������
*/
int SalesCfg::isDigit(const QString &src)
{
	QByteArray ba = src.toLatin1();//QString ת��Ϊ char*
	const char *s = ba.data();
	while (*s && *s >= '0' && *s <= '9')
		s++;
	if (*s)
	{ //���Ǵ�����
		return -1;
	}
	else
	{ //������
		return 0;
	}
}

void SalesCfg::writeFile(QTextStream &qos, QTextStream &qis, QString args)
{
	//����Ƿ����ظ��ģ����ظ��ľ͸���
	QString readLine;
	QStringList splist;
	QMap<QString, QStringList> Info;
	while (qis.readLineInto(&readLine)){
		splist = readLine.split(";");
		QStringList otherInfo;
		for (int j = 1; j < splist.size(); j++)
			otherInfo.push_back(splist[j]);
		Info.insert(splist[0], otherInfo);
		readLine.clear();
	}

	int index = args.indexOf(";");
	QString id = args.left(index);
	int repeats = 0;
	for (QMap<QString, QStringList>::const_iterator iter = Info.constBegin(); iter != Info.constEnd(); iter++)
	{
		if (id == iter.key())
		{
			++repeats;
		}
	}
	qos << args;
}
