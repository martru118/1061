#include <iostream>
using namespace std;

class Point
{
  //DO NOT CHANGE THIS CLASS
  public:
  int x, y;

  Point() {}
  Point(int x, int y) { this->x = x; this->y = y; }
  
  friend ostream& operator<<(ostream& os, const Point& pt) {
    os << "(" << pt.x << ", " << pt.y << ")";
    return os;
  }
};

class Shape
{
  protected:
  Point _location;

  public:
  Shape() {}
  Shape(const Point& location) : _location(location) {}
  ~Shape() {}
  
  virtual void draw() {
    cout << "\tlocation: " << _location << endl;
  }
  
  virtual void get_info_from_user() {
    cout << "Enter position: ";
    cin >> _location.x >> _location.y;
  }
};

class Tri: public Shape, Point
{
  protected:
  int _width, _height;

  public:
  Tri(): Shape(), Point()
  {
    _width = 0;
    _height = 0;
  }
  ~Tri() {}

  //override from Shape()
  void get_info_from_user() {
    Shape::get_info_from_user();
    cout << "Enter width and height: ";
    cin >> _width >> _height;
  } 
  
  //override from Shape()
  void draw() {
    cout << "TRIANGLE" << endl;
    Shape::draw();
    cout << *this << endl;
  }

  //override from Point()
  friend ostream& operator<<(ostream& os, const Tri& s) {
    static_cast<const Point&>(s);
    os << "\twidth and height: (" << s._width << ", " << s._height << ")";
    return os;
  }
};

class Cir: public Shape, Point
{
  protected:
  int _radius;

  public:
  Cir(): Shape(), Point()
  {
    _radius = 0;
  }
  ~Cir() {}

  //override from Shape()
  void draw() {
    cout << "RADIUS" << endl;
    Shape::draw();
    cout << *this << endl;
  }

  //override from Shape()
  void get_info_from_user() {
    Shape::get_info_from_user();
    cout << "Enter radius: ";
    cin >> _radius;
  }

  //override from Point()
  friend ostream& operator<<(ostream& os, const Cir& s) {
    static_cast<const Point&>(s);
    os << "\tradius: (" << s._radius << ")";
    return os;
  }
};

/*DO NOT CHANGE CODE BELOW THIS LINE*/
#define MAX_SHAPES 10

void print_shapes(Shape** shapes, int n)
{
  for (int i=0; i<n; ++i) {
    cout << "[" << i << "] "; shapes[i]->draw();
  }
}

int main()
{
  Shape* shapes[MAX_SHAPES];

  int n = 0;
  char shape_choice;
  do {
    cout << "Choose a shape to add" << endl;
    cout << "\t(a) for triangle" << endl;
    cout << "\t(b) for circle" << endl;
    cout << "\t(p) to print the shapes" << endl;
    cout << "\t(0-9) to modify a shape" << endl;
    cout << "\t(q) to exit" << endl;
    cout << ": ";
    cin >> shape_choice;

    if (shape_choice == 'q') break;
    
    switch(shape_choice)
    {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        shapes[((int) shape_choice) - 48]->get_info_from_user();
      break;
      case 'a':
        if (n >=  MAX_SHAPES) {
          cout << "== Cannot add any more shapes ==" << endl;
          continue;
        }      
        cout << "== You selected a triangle. ==" << endl;
        shapes[n] = new Tri();
        shapes[n]->get_info_from_user();
        ++n;
      break;
      case 'b':
        if (n >=  MAX_SHAPES) {
          cout << "== Cannot add any more shapes ==" << endl;
          continue;
        }
        cout << "== You selected a circle. ==" << endl;
        shapes[n] = new Cir();
        shapes[n]->get_info_from_user();
        ++n;     
      break;
      case 'p':
        print_shapes(shapes, n);
      break;
      case 'q':
      break;
      default:
        cerr << "== Invalid choice ==" << endl;
      break;
    }
  } while (true);

  for (int i=0; i<n; ++i) delete shapes[i];
}
