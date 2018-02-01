#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reversiwidget.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>
#include "slottedlist.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
    QWidget *window = new QWidget;

    ReversiWidget *w = new ReversiWidget();
    connect(w, SIGNAL(Menu()), this, SLOT(handleMenu()));

    QHBoxLayout *qhbox = new QHBoxLayout;

    QWidget * qw1 = new QWidget;
    qw1->setFixedSize(300,640);

    QWidget * qw2 = new QWidget;
    qw2->setFixedSize(300,640);

    //white panel
    QVBoxLayout * qvbox1 = new QVBoxLayout;

    QLabel *whites = new QLabel();
    whites->setText("White Score");
    whites->setFont(QFont("Tahoma",20));
    whites->setAlignment(Qt::AlignCenter);

    QLabel *white_score = new QLabel();
    white_score->setText("2");
    white_score->setFont(QFont("Tahoma",40));
    white_score->setAlignment(Qt::AlignCenter);
    white_score->setStyleSheet("background: black; color: white;");

    QObject::connect(w, SIGNAL(whiteScoreChanged(QString)), white_score, SLOT(setText(QString)));

    QLabel *whitem = new QLabel();
    whitem->setText("White Moves");
    whitem->setFont(QFont("Tahoma",20));
    whitem->setAlignment(Qt::AlignCenter);

    SlottedList *qlw1 = new SlottedList();

    QObject::connect(w, SIGNAL(whiteMoved(QString)), qlw1, SLOT(insertInList(QString)));
    qvbox1->addWidget(whites);
    qvbox1->addWidget(white_score);
    qvbox1->addWidget(whitem);
    qvbox1->addWidget(qlw1, 5);
    qw1->setLayout(qvbox1);

    //black panel
    QVBoxLayout * qvbox2 = new QVBoxLayout;

    QLabel *blacks = new QLabel();
    blacks->setText("Black Score");
    blacks->setFont(QFont("Tahoma",20));
    blacks->setAlignment(Qt::AlignCenter);

    QLabel *black_score = new QLabel();
    black_score->setText("2");
    black_score->setFont(QFont("Tahoma",40));
    black_score->setAlignment(Qt::AlignCenter);
    black_score->setStyleSheet("background: white; color: black;");

    QObject::connect(w, SIGNAL(blackScoreChanged(QString)), black_score, SLOT(setText(QString)));

    QLabel *blackm = new QLabel();
    blackm->setText("Black Moves");
    blackm->setFont(QFont("Tahoma",20));
    blackm->setAlignment(Qt::AlignCenter);

    SlottedList *qlw2 = new SlottedList();

    QObject::connect(w, SIGNAL(blackMoved(QString)), qlw2, SLOT(insertInList(QString)));
    qvbox2->addWidget(blacks);
    qvbox2->addWidget(black_score);
    qvbox2->addWidget(blackm);
    qvbox2->addWidget(qlw2, 5);
    qw2->setLayout(qvbox2);

    //whole package
    qhbox->addWidget(qw1);
    qhbox->addWidget(w);
    qhbox->addWidget(qw2);

    window->setLayout(qhbox);
    window->setFixedSize(1400,700);

    window->setWindowTitle("Cpu Vs Cpu");
    window->setWindowIcon(QIcon(":/icons/icon.png"));
    window->show();
    w->start();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->hide();

    QWidget *window = new QWidget;

    ReversiWidget *w = new ReversiWidget();
    connect(w, SIGNAL(Menu()), this, SLOT(handleMenu()));


    QHBoxLayout *qhbox = new QHBoxLayout;

    QWidget * qw1 = new QWidget;
    qw1->setFixedSize(300,640);

    QWidget * qw2 = new QWidget;
    qw2->setFixedSize(300,640);

    //white panel
    QVBoxLayout * qvbox1 = new QVBoxLayout;

    QLabel *whites = new QLabel();
    whites->setText("White Score");
    whites->setFont(QFont("Tahoma",20));
    whites->setAlignment(Qt::AlignCenter);

    QLabel *white_score = new QLabel();
    white_score->setText("2");
    white_score->setFont(QFont("Tahoma",40));
    white_score->setAlignment(Qt::AlignCenter);
    white_score->setStyleSheet("background: black; color: white;");

    QObject::connect(w, SIGNAL(whiteScoreChanged(QString)), white_score, SLOT(setText(QString)));

    QLabel *whitem = new QLabel();
    whitem->setText("White Moves");
    whitem->setFont(QFont("Tahoma",20));
    whitem->setAlignment(Qt::AlignCenter);

    SlottedList *qlw1 = new SlottedList();

    QObject::connect(w, SIGNAL(whiteMoved(QString)), qlw1, SLOT(insertInList(QString)));
    qvbox1->addWidget(whites);
    qvbox1->addWidget(white_score);
    qvbox1->addWidget(whitem);
    qvbox1->addWidget(qlw1, 5);
    qw1->setLayout(qvbox1);

    //black panel
    QVBoxLayout * qvbox2 = new QVBoxLayout;

    QLabel *blacks = new QLabel();
    blacks->setText("Black Score");
    blacks->setFont(QFont("Tahoma",20));
    blacks->setAlignment(Qt::AlignCenter);

    QLabel *black_score = new QLabel();
    black_score->setText("2");
    black_score->setFont(QFont("Tahoma",40));
    black_score->setAlignment(Qt::AlignCenter);
    black_score->setStyleSheet("background: white; color: black;");

    QObject::connect(w, SIGNAL(blackScoreChanged(QString)), black_score, SLOT(setText(QString)));

    QLabel *blackm = new QLabel();
    blackm->setText("Black Moves");
    blackm->setFont(QFont("Tahoma",20));
    blackm->setAlignment(Qt::AlignCenter);

    SlottedList *qlw2 = new SlottedList();

    QObject::connect(w, SIGNAL(blackMoved(QString)), qlw2, SLOT(insertInList(QString)));
    qvbox2->addWidget(blacks);
    qvbox2->addWidget(black_score);
    qvbox2->addWidget(blackm);
    qvbox2->addWidget(qlw2, 5);
    qw2->setLayout(qvbox2);

    //whole package
    qhbox->addWidget(qw1);
    qhbox->addWidget(w);
    qhbox->addWidget(qw2);

    window->setLayout(qhbox);
    window->setFixedSize(1400,700);

    window->setWindowTitle("Me Vs Cpu");
    window->setWindowIcon(QIcon(":/icons/icon.png"));
    window->show();

    w->start({-1, });


}

void MainWindow::handleMenu()
{
    this->show();
}
