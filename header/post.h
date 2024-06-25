#ifndef POST_H
#define POST_H

#include <QDialog>
#include "project.h"

namespace Ui {
class post;
}

class post : public QDialog
{
    Q_OBJECT

public:
    explicit post(QWidget *parent = nullptr);
    post(QWidget *parent, int rowIndex,Post** post, string* name );

    ~post();

private slots:
    void on_exit_clicked();

    void on_postComment_clicked();

    void on_like_clicked();

private:
    Ui::post *ui;
    int rowInd;
    Post** p;
    string* name;
};

#endif // POST_H
