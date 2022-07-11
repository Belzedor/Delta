#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QProcess>
#include <vector>
#include <set>

std::vector<int> init_pair(2,0);
std::vector<std::vector<int>> init_data(1,init_pair);
std::vector<std::vector<std::vector<int>>> full_data(10, init_data);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void count_data(int begin, int width, int depth, int data_num)
{
    if (width == 0 || depth == 0)
    {
        full_data[data_num - 1].clear();
        return;
    }

    std::vector<std::vector<int>> data;
    std::vector<int> pair;

    pair.insert(pair.begin(), {'P', begin});
    data.push_back(pair);
    pair.clear();
    pair.insert(pair.begin(), {'C', begin + 1 + depth});
    data.push_back(pair);

    for (int i = 2; true; i++)
    {
        pair.clear();
        if (i % 3 == 0)
        {
            pair.insert(pair.begin(), {'P', data[i-1][1] + depth + 1});
            if (pair[1] > 620 - 2*depth - width - 2) break;
            data.push_back(pair);
            i++;
            pair.clear();
            pair.insert(pair.begin(), {'C', data[i-1][1] + depth + 1});
            if (pair[1] > 620 - 2*depth - width - 2) break;
            data.push_back(pair);
            continue;
        }
        else
        {
            pair.insert(pair.begin(), {'C', data[i-1][1] + width});
            if (pair[1] > 620 - 2*depth - width - 2) break;
            data.push_back(pair);
            continue;
        }
    }

    full_data[data_num - 1] = data;
}

int count_delta(int data_num)
{
    std::set<int> delta_set;
    for(int i = 0; i < 10; i++)
    {
        if (i != data_num - 1 && full_data[i][0][0] != 0)
        {
            for (long long unsigned int j = 0; j < full_data[i].size(); j++)
            {
                if (full_data[i][j][0] == 'P')
                {
                    for (long long unsigned int z = 0; z < full_data[data_num - 1].size(); z++)
                    {
                        if(full_data[data_num - 1][z][0] == 'C')
                        {
                            delta_set.insert(abs(full_data[i][j][1] - full_data[data_num - 1][z][1]));
                        }
                    }
                }
            }
        }
    }

    if(delta_set.size() == 0) return 0;
    auto it = delta_set.begin();
    return *it;
}

// --------------------------- 1 слот
void MainWindow::on_delta_1_editingFinished()
{
    int begin = ui->begin_1->value();
    int width = ui->width_1->value();
    int depth = ui->depth_1->value();

    count_data(begin, width, depth, 1);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_begin_1_editingFinished()
{
    int begin = ui->begin_1->value();
    int width = ui->width_1->value();
    int depth = ui->depth_1->value();

    count_data(begin, width, depth, 1);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_width_1_editingFinished()
{
    int begin = ui->begin_1->value();
    int width = ui->width_1->value();
    int depth = ui->depth_1->value();

    count_data(begin, width, depth, 1);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_depth_1_editingFinished()
{
    int begin = ui->begin_1->value();
    int width = ui->width_1->value();
    int depth = ui->depth_1->value();

    count_data(begin, width, depth, 1);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

// --------------------------- 2 слот
void MainWindow::on_delta_2_editingFinished()
{
    int begin = ui->begin_2->value();
    int width = ui->width_2->value();
    int depth = ui->depth_2->value();

    count_data(begin, width, depth, 2);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_begin_2_editingFinished()
{
    int begin = ui->begin_2->value();
    int width = ui->width_2->value();
    int depth = ui->depth_2->value();

    count_data(begin, width, depth, 2);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_width_2_editingFinished()
{
    int begin = ui->begin_2->value();
    int width = ui->width_2->value();
    int depth = ui->depth_2->value();

    count_data(begin, width, depth, 2);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_depth_2_editingFinished()
{
    int begin = ui->begin_2->value();
    int width = ui->width_2->value();
    int depth = ui->depth_2->value();

    count_data(begin, width, depth, 2);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

// --------------------------- 3 слот
void MainWindow::on_delta_3_editingFinished()
{
    int begin = ui->begin_3->value();
    int width = ui->width_3->value();
    int depth = ui->depth_3->value();

    count_data(begin, width, depth, 3);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_begin_3_editingFinished()
{
    int begin = ui->begin_4->value();
    int width = ui->width_4->value();
    int depth = ui->depth_4->value();

    count_data(begin, width, depth, 3);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_width_3_editingFinished()
{
    int begin = ui->begin_3->value();
    int width = ui->width_3->value();
    int depth = ui->depth_3->value();

    count_data(begin, width, depth, 3);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_depth_3_editingFinished()
{
    int begin = ui->begin_3->value();
    int width = ui->width_3->value();
    int depth = ui->depth_3->value();

    count_data(begin, width, depth, 3);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

// --------------------------- 4 слот
void MainWindow::on_delta_4_editingFinished()
{
    int begin = ui->begin_4->value();
    int width = ui->width_4->value();
    int depth = ui->depth_4->value();

    count_data(begin, width, depth, 4);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_begin_4_editingFinished()
{
    int begin = ui->begin_4->value();
    int width = ui->width_4->value();
    int depth = ui->depth_4->value();

    count_data(begin, width, depth, 4);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_width_4_editingFinished()
{
    int begin = ui->begin_4->value();
    int width = ui->width_4->value();
    int depth = ui->depth_4->value();

    count_data(begin, width, depth, 4);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_depth_4_editingFinished()
{
    int begin = ui->begin_4->value();
    int width = ui->width_4->value();
    int depth = ui->depth_4->value();

    count_data(begin, width, depth, 4);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}
// --------------------------- 5 слот
void MainWindow::on_delta_5_editingFinished()
{
    int begin = ui->begin_5->value();
    int width = ui->width_5->value();
    int depth = ui->depth_5->value();

    count_data(begin, width, depth, 5);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_begin_5_editingFinished()
{
    int begin = ui->begin_5->value();
    int width = ui->width_5->value();
    int depth = ui->depth_5->value();

    count_data(begin, width, depth, 5);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_width_5_editingFinished()
{
    int begin = ui->begin_5->value();
    int width = ui->width_5->value();
    int depth = ui->depth_5->value();

    count_data(begin, width, depth, 5);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_depth_5_editingFinished()
{
    int begin = ui->begin_5->value();
    int width = ui->width_5->value();
    int depth = ui->depth_5->value();

    count_data(begin, width, depth, 5);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}
// --------------------------- 6 слот
void MainWindow::on_delta_6_editingFinished()
{
    int begin = ui->begin_6->value();
    int width = ui->width_6->value();
    int depth = ui->depth_6->value();

    count_data(begin, width, depth, 6);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_begin_6_editingFinished()
{
    int begin = ui->begin_6->value();
    int width = ui->width_6->value();
    int depth = ui->depth_6->value();

    count_data(begin, width, depth, 6);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_width_6_editingFinished()
{
    int begin = ui->begin_6->value();
    int width = ui->width_6->value();
    int depth = ui->depth_6->value();

    count_data(begin, width, depth, 6);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_depth_6_editingFinished()
{
    int begin = ui->begin_6->value();
    int width = ui->width_6->value();
    int depth = ui->depth_6->value();

    count_data(begin, width, depth, 6);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}
// --------------------------- 7 слот
void MainWindow::on_delta_7_editingFinished()
{
    int begin = ui->begin_7->value();
    int width = ui->width_7->value();
    int depth = ui->depth_7->value();

    count_data(begin, width, depth, 7);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_begin_7_editingFinished()
{
    int begin = ui->begin_7->value();
    int width = ui->width_7->value();
    int depth = ui->depth_7->value();

    count_data(begin, width, depth, 7);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_width_7_editingFinished()
{
    int begin = ui->begin_7->value();
    int width = ui->width_7->value();
    int depth = ui->depth_7->value();

    count_data(begin, width, depth, 7);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_depth_7_editingFinished()
{
    int begin = ui->begin_7->value();
    int width = ui->width_7->value();
    int depth = ui->depth_7->value();

    count_data(begin, width, depth, 7);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

// --------------------------- 8 слот
void MainWindow::on_delta_8_editingFinished()
{
    int begin = ui->begin_8->value();
    int width = ui->width_8->value();
    int depth = ui->depth_8->value();

    count_data(begin, width, depth, 8);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_begin_8_editingFinished()
{
    int begin = ui->begin_8->value();
    int width = ui->width_8->value();
    int depth = ui->depth_8->value();

    count_data(begin, width, depth, 8);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_width_8_editingFinished()
{
    int begin = ui->begin_8->value();
    int width = ui->width_8->value();
    int depth = ui->depth_8->value();

    count_data(begin, width, depth, 8);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_depth_8_editingFinished()
{
    int begin = ui->begin_8->value();
    int width = ui->width_8->value();
    int depth = ui->depth_8->value();

    count_data(begin, width, depth, 8);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}
// --------------------------- 9 слот
void MainWindow::on_delta_9_editingFinished()
{
    int begin = ui->begin_9->value();
    int width = ui->width_9->value();
    int depth = ui->depth_9->value();

    count_data(begin, width, depth, 9);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_begin_9_editingFinished()
{
    int begin = ui->begin_9->value();
    int width = ui->width_9->value();
    int depth = ui->depth_9->value();

    count_data(begin, width, depth, 9);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_width_9_editingFinished()
{
    int begin = ui->begin_9->value();
    int width = ui->width_9->value();
    int depth = ui->depth_9->value();

    count_data(begin, width, depth, 9);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_depth_9_editingFinished()
{
    int begin = ui->begin_9->value();
    int width = ui->width_9->value();
    int depth = ui->depth_9->value();

    count_data(begin, width, depth, 9);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}
// --------------------------- 10 слот
void MainWindow::on_delta_10_editingFinished()
{
    int begin = ui->begin_10->value();
    int width = ui->width_10->value();
    int depth = ui->depth_10->value();

    count_data(begin, width, depth, 10);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_begin_10_editingFinished()
{
    int begin = ui->begin_10->value();
    int width = ui->width_10->value();
    int depth = ui->depth_10->value();

    count_data(begin, width, depth, 10);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_width_10_editingFinished()
{
    int begin = ui->begin_10->value();
    int width = ui->width_10->value();
    int depth = ui->depth_10->value();

    count_data(begin, width, depth, 10);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_depth_10_editingFinished()
{
    int begin = ui->begin_10->value();
    int width = ui->width_10->value();
    int depth = ui->depth_10->value();

    count_data(begin, width, depth, 10);
    ui->delta_1->setValue(count_delta(1));
    ui->delta_2->setValue(count_delta(2));
    ui->delta_3->setValue(count_delta(3));
    ui->delta_4->setValue(count_delta(4));
    ui->delta_5->setValue(count_delta(5));
    ui->delta_6->setValue(count_delta(6));
    ui->delta_7->setValue(count_delta(7));
    ui->delta_8->setValue(count_delta(8));
    ui->delta_9->setValue(count_delta(9));
    ui->delta_10->setValue(count_delta(10));
}

void MainWindow::on_pushButton_clicked()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

