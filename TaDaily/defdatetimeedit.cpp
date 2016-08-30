#include "defdatetimeedit.h"

DefDateTimeEdit::DefDateTimeEdit(QWidget *parent):
  QDateTimeEdit(parent)
{
	setCalendarPopup(true);
	m_Calendar = new QCalendarWidget(this);
	setCalendarWidget(m_Calendar);
	connect(m_Calendar, SIGNAL(clicked(QDate)), this, SLOT(getDateTime(QDate)));
	setDisplayFormat("yyyy-MM-dd");
	setMyStyle();
}

DefDateTimeEdit::~DefDateTimeEdit()
{
	delete m_Calendar;
}

void DefDateTimeEdit::setMyStyle()
{
	QString strTemp;
	//QWidget
	strTemp.append("QWidget{font:normal 10pt Microsoft YaHei;}");
	strTemp.append("QWidget#CalTopWidget{background-color:rgb(0, 159, 149);}");
	strTemp.append("QWidget#CalBottomWidget{background-color:white;}");
	//QLabel
	strTemp.append("QLabel#CalLabel{border:1px solid lightgray; color:rgb(0, 159, 149);}");
	
	//QPushButton
	strTemp.append("QPushButton#CalPushBtnT1{border:0px;}");
	strTemp.append("QPushButton#CalPushBtnT1:hover,QPushButton#CalPushBtnT1:pressed\
	                           {background-color:rgb(0, 102, 96);}");
	strTemp.append("QPushButton#CalPushBtnT2{border:1px solid lightgray; color:rgb(0, 159, 149);}");
	strTemp.append("QPushButton#CalPushBtnT2:hover,QPushButton#CalPushBtnT2:pressed\
	                           {background-color:rgb(231, 231, 231);}");
	//QDateTimeEdit
	strTemp.append("QDateTimeEdit{border:1px solid gray; height:24px; }");
	strTemp.append("QDateTimeEdit::down-arrow{image:url(Resources/calendar.png);}");
	strTemp.append("QDateTimeEdit::drop-down{width:24px; border:0px solid red;\
	                           subcontrol-origin: padding;subcontrol-position: top right;}");

	this->setStyleSheet(strTemp);
}

void DefDateTimeEdit::getDateTime(const QDate &date)
{
	this->setDate(date);
	emit update(date);
}
