#include "includes.h"


// Холмик
class Hill
{
private:
  double x; // координаты
  double y; // неровности
  double sigma; // средне квадратичное отклонение
  double hight; // "высота" холма
public:
  Hill(double size_x, double size_y);
  Hill(double x0, double y0, 
       double sigma0, double hight0):
       x(x0), y(y0), hight(hight0)
       {sigma = abs(sigma0);}

  // Нормальное распределение в точке относительно холма
  double Gauss(double x0, double y0) const;
};

class Stoun
{
private:
  double x;
  double y;
  double r;
public:
  Stoun(double size_x, double size_y);
  Stoun(double x0, double y0, 
        double r0): x(x0), y(y0), r(r0){}

  double get_x() const {return x;}
  double get_y() const {return y;}
  double get_r() const {return r;}
  double dist(double x0, double y0) const;
};

class Log
{
private:
  double x1;
  double y1;
  double x2;
  double y2;
  double r;
public:
  Log(double size_x, double size_y);
  Log(double x01, double y01, 
      double x02, double y02, 
      double r0): x1(x01), y1(y01), 
                  x2(x02), y2(y02), r(r0){}

  double get_x1() const {return x1;}
  double get_y1() const {return y1;}
  double get_x2() const {return x2;}
  double get_y2() const {return y2;}
  double get_r() const {return r;}
  double dist(double x0, double y0) const;
};

// Бездорожье
class NoWay
{
private:
  double size_x; // размеры 
  double size_y; // поверхности
  std::vector<Hill> hills; // вектор холмов
  std::vector<Stoun> stouns;
  std::vector<Log> logs;
  int count_hills; // количество холмов
  int count_stouns;
  int count_logs;
public:
  NoWay() = default;
  NoWay(double x, double y, int count_hills = 0, 
        int count_stouns = 0, int count_logs = 0);


  // TODO написать функции
  void add_hill();
  void add_stone();
  void add_log();



  // Вывод поверхности в файл для GNUplot
  void print(std::ofstream &file1, std::ofstream &file2, 
             std::ofstream &file3) const;
};

/*class Rover
{
private:
  double x;
  double y;
  std::vector<double> rotation;
  double speed;
};*/

// Двумерная функция Гаусса о нормальном распределении
double f(double x, double y, Hill H);