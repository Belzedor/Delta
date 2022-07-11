#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_delta_1_editingFinished();

    void on_delta_2_editingFinished();

    void on_delta_3_editingFinished();

    void on_delta_4_editingFinished();

    void on_delta_5_editingFinished();

    void on_delta_6_editingFinished();

    void on_delta_7_editingFinished();

    void on_delta_8_editingFinished();

    void on_delta_9_editingFinished();

    void on_delta_10_editingFinished();

    void on_begin_1_editingFinished();

    void on_width_1_editingFinished();

    void on_depth_1_editingFinished();

    void on_begin_2_editingFinished();

    void on_width_2_editingFinished();

    void on_depth_2_editingFinished();

    void on_begin_3_editingFinished();

    void on_width_3_editingFinished();

    void on_depth_3_editingFinished();

    void on_begin_4_editingFinished();

    void on_width_4_editingFinished();

    void on_depth_4_editingFinished();

    void on_begin_5_editingFinished();

    void on_width_5_editingFinished();

    void on_depth_5_editingFinished();

    void on_begin_6_editingFinished();

    void on_width_6_editingFinished();

    void on_depth_6_editingFinished();

    void on_begin_7_editingFinished();

    void on_width_7_editingFinished();

    void on_depth_7_editingFinished();

    void on_begin_8_editingFinished();

    void on_width_8_editingFinished();

    void on_depth_8_editingFinished();

    void on_begin_9_editingFinished();

    void on_width_9_editingFinished();

    void on_depth_9_editingFinished();

    void on_begin_10_editingFinished();

    void on_width_10_editingFinished();

    void on_depth_10_editingFinished();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
