#include "BorderLayout.h"
#include "Window.h"
#include <QTextBrowser>
#include <QLabel>

Window::Window()
{
    QTextBrowser *centralWidget = new QTextBrowser;
    centralWidget->setPlainText(tr("Central widget"));

    BorderLayout *layout = new BorderLayout;
    layout->addWidget(centralWidget, BorderLayout::Center);
    layout->addWidget(createLabel("North"), BorderLayout::North);
    layout->addWidget(createLabel("West"), BorderLayout::West);
    layout->addWidget(createLabel("East 1"), BorderLayout::East);
    layout->addWidget(createLabel("East 2") , BorderLayout::East);
    layout->addWidget(createLabel("South"), BorderLayout::South);
    setLayout(layout);

    setWindowTitle(tr("Border Layout"));
}

QLabel *Window::createLabel(const QString &text)
{
    QLabel *label = new QLabel(text);
    label->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
    return label;
}
