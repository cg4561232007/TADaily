#ifndef DEFDATETIMEEDIT_H
#define DEFDATETIMEEDIT_H

#include "qdatetime.h"
#include "qdatetimeedit.h"
#include "qcalendarwidget.h"

class DefDateTimeEdit : public QDateTimeEdit
{
  Q_OBJECT

public:
  explicit DefDateTimeEdit(QWidget *parent=0);
  ~DefDateTimeEdit();
  void setMyStyle();

protected slots:
  void getDateTime(const QDate&);

signals:
  void update(const QDate&);

private:
	QCalendarWidget *m_Calendar;
};

#endif // DEFDATETIMEEDIT_H
