/*
 * Qt6.3.1
 * Simple inventory application
 * Using the skills the have covered so far
 *
 * Make a class
 * Fill in the code
 * Monitor input
 * Focus on QDataStream
 *
 *
 */
#include <QCoreApplication>
#include <QTextStream>
#include "inventory.h"


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Inventory inventory;

    inventory.app();

    return app.exec();
}
