#ifndef HOME_H
#define HOME_H
#include <QListWidgetItem>

#include <QDialog>

namespace Ui {
class home;
}

class home : public QDialog
{
    Q_OBJECT

public:
    explicit home(QWidget *parent = nullptr);
    ~home();

private slots:
    void onItemPressed(QListWidgetItem *item);

    void on_back_clicked();

private:
    Ui::home *ui;
};

#endif // HOME_H
