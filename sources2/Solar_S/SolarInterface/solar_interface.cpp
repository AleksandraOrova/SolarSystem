#include "solar_interface.h"

Solar_Interface::Solar_Interface(QString path_, QWidget *parent)
    : QWidget(parent), path(path_)
{
    // ui->setUi(this);
    setWindowTitle("Solar System");
    setMinimumSize(1280, 720);
    setMaximumSize(1280, 720);

    save_b = new QPushButton("SAVE", this);
    save_b->setGeometry(5, 20, 90, 30);

    load_b = new QPushButton("LOAD", this);
    load_b->setGeometry(5, 70, 90, 30);

    in_text = new QPushButton("PRINT", this);
    in_text->setGeometry(5, 120, 90, 30);

    speed_up = new QPushButton("SPEED UP", this);
    speed_up->setGeometry(5, 170, 90, 30);

    speed_down = new QPushButton("SPEED DOWN", this);
    speed_down->setGeometry(5, 220, 90, 30);

    inp = new QLineEdit("inp.txt", this);
    inp->setGeometry(5, 270, 90, 20);

    std::cout << path.toStdString() << std::endl;

    try
    {
        //my_system.input("input.txt");
        my_system.output("out.txt", false);
    }
    catch (std::exception & ex)
    {
        std::cout << ex.what() << std::endl;
    }

    QMetaObject::connectSlotsByName(save_b);
    QObject::connect(save_b, SIGNAL(clicked()), SLOT(on_save_b_clicked()));
    QObject::connect(load_b, SIGNAL(clicked()), SLOT(on_load_b_clicked()));
    QObject::connect(in_text, SIGNAL(clicked()), SLOT(on_in_text_clicked()));
    QObject::connect(speed_up, SIGNAL(clicked()), SLOT(on_speed_up_clicked()));
    QObject::connect(speed_down, SIGNAL(clicked()), SLOT(on_speed_down_clicked()));

    curr_time = 0;
    speed =  0.01;
    startTimer(20);
}

void Solar_Interface::timerEvent(QTimerEvent *)
{
    update();
    // recountTime();
}

void Solar_Interface::paintEvent(QPaintEvent *)
{
    if (my_system.getSize() == 0) return;
    my_system.planetsMovement(curr_time);

    std::string info = "";

    QPainter paint(this);
    clear(paint);

    paint.fillRect(100, 10, 1170, 700, QBrush(Qt::black));

    std::vector<Planet> planets = my_system.getPlanets();
    Star sun = my_system.getStar();

    paint.setBrush(QBrush(Qt::yellow));
    paint.drawEllipse(250 + sun.getPosition().getX() - sun.getRad(),
                      10 + sun.getPosition().getY() - sun.getRad(),
                      2 * sun.getRad(), 2 * sun.getRad());

    paint.setPen(Qt::white);
    info += "Sun: " + doubleToString(sun.getPosition().getX()) +
            ", " + doubleToString(sun.getPosition().getY());
    paint.drawText(110, 30, info.c_str());
    paint.setPen(Qt::black);

    for (std::vector<Planet>::iterator i = planets.begin(); i != planets.end(); ++i)
    {
        info = i->getName() + ": " + doubleToString(i->getPosition().getX()) +
               ", " + doubleToString(i->getPosition().getY());
        paint.setPen(Qt::white);
        paint.drawText(110, 45 + 15 * std::distance(planets.begin(), i), info.c_str());
        paint.setPen(Qt::black);

        if (i->getColor() == "blue")
        {
            paint.setBrush(QBrush(Qt::blue));
        }
        else if (i->getColor() == "red")
        {
            paint.setBrush(QBrush(Qt::red));
        }
        else if (i->getColor() == "green")
        {
            paint.setBrush(QBrush(Qt::green));
        }
        else if (i->getColor() == "gray")
        {
            paint.setBrush(QBrush(Qt::gray));
        }
        else if (i->getColor() == "magenta")
        {
            paint.setBrush(QBrush(Qt::magenta));
        }
        else
        {
            paint.setBrush(QBrush(Qt::white));
        }

        paint.drawEllipse(250 + i->getPosition().getX() - i->getRad(),
                          10 + i->getPosition().getY() - i->getRad(),
                          2 * i->getRad(), 2 * i->getRad());
    }

    if (curr_time > 6.28)
    {
        curr_time = 0;
    }

    curr_time += speed;
}

void Solar_Interface::clear(QPainter & paint)
{
    paint.eraseRect(100, 10, 1170, 700);
}

Solar_Interface::~Solar_Interface()
{
    delete load_b;
    delete save_b;
}

void Solar_Interface::on_save_b_clicked()
{
    try
    {
        my_system.save();
    }
    catch (std::exception & ex) {
        std::cout << ex.what() << std::endl;
    };
}

void Solar_Interface::on_load_b_clicked()
{
    try
    {
        my_system.input(inp->text().toStdString().c_str());
    }
    catch (std::exception & ex) {
        std::cout << ex.what() << std::endl;
    };

    curr_time = 0;
}

void Solar_Interface::on_in_text_clicked()
{
    try
    {
        my_system.output("out.txt", true);
    }
    catch (std::exception & ex) {
        std::cout << ex.what() << std::endl;
    };

#ifdef WIN32
    system("notepad out.txt");

#else
    system("cat out.txt");

#endif
}

void Solar_Interface::on_speed_up_clicked()
{
    speed += 0.001;
}

void Solar_Interface::on_speed_down_clicked()
{
    if (speed >= 0.002)
    {
        speed -= 0.001;
    }
}
