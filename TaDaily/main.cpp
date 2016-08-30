#include "tadaily.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TaDaily w;
	w.show();
	return a.exec();
}
