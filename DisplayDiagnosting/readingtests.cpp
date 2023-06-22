
#include "readingtests.h"

#include <QGuiApplication>
#include <QKeyEvent>
#include <QLinearGradient>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QPushButton>
#include <QRect>
#include <QScreen>
#include <QTimer>
#include <QVBoxLayout>
#include <QtWidgets>

const int HightDelta = 15;
const int FontSize = 11;
const int TextAlighment = 4;

QList<QColor> BackbroundColor{QColor(Qt::black),
                              QColor(Qt::white),
                              QColor(Qt::green),
                              QColor(Qt::blue)};

QList<QColor> TextColor{QColor(Qt::white), QColor(Qt::black), QColor(Qt::blue), QColor(Qt::yellow)};

ReadingTests::ReadingTests(bool isAutoTest, size_t delay, QWidget *parent)
    : QWidget{parent}
    , m_IsAutoTest{isAutoTest}
    , m_Delay{delay}
{
    backButton = new QPushButton("X", this);
    backButton->setStyleSheet("background-color: red;");
    backButton->setGeometry(
        QRect(QPoint(QGuiApplication::primaryScreen()->geometry().width() - 35, 5), QSize(30, 30)));
    connect(backButton, &QPushButton::clicked, this, &QWidget::close);

    m_TestIndex = 0;
    setFocusPolicy(Qt::StrongFocus);

    if (m_IsAutoTest) {
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &ReadingTests::SimulateRightArrowKey);
        timer->start(m_Delay * 1000);
    }
}

ReadingTests::~ReadingTests()
{
    if (backButton != nullptr)
        delete backButton;
    if (timer != nullptr)
        delete timer;
}

void ReadingTests::MakeTest(int indexOfList)
{
    m_BackGroundColor = BackbroundColor[indexOfList];
    m_TextColor = TextColor[indexOfList];
    update();
}

void ReadingTests::SimulateRightArrowKey()
{
    QKeyEvent *event = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Right, Qt::NoModifier);
    keyPressEvent(event);
    delete event;
}

void ReadingTests::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(rect(), m_BackGroundColor);
    painter.setPen(m_TextColor);
    QFont font("Sitka Banner Semibold", FontSize);
    painter.setFont(font);

    QScreen *screenGeometry = QGuiApplication::primaryScreen();
    QString printedText = "Можете прочитати?";
    int64_t textLength = (printedText.length() + HightDelta) * TextAlighment;

    int64_t rowCount = screenGeometry->geometry().height() / HightDelta;
    int64_t cellCount = screenGeometry->geometry().width() / textLength;
    int64_t cellWidth = screenGeometry->geometry().width() / cellCount;
    int64_t cellHeight = screenGeometry->geometry().height() / rowCount;

    for (int64_t i = 0; i < rowCount; i++) {
        for (int64_t j = 0; j < cellCount; j++) {
            QRect rect(j * cellWidth, i * cellHeight, cellWidth, cellHeight);
            painter.drawText(rect, Qt::AlignCenter, printedText);
        }
    }
}

void ReadingTests::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left:
        m_TestIndex = (m_TestIndex - 1 + m_ReadingList.size()) % m_ReadingList.size();
        MakeTest(m_ReadingList[m_TestIndex]);
        break;
    case Qt::Key_Right:
        m_TestIndex = (m_TestIndex + 1) % m_ReadingList.size();
        MakeTest(m_ReadingList[m_TestIndex]);
        break;
    default:
        QWidget::keyPressEvent(event);
        break;
    }
}
