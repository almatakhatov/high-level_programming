#include "std_lib_facilities.h"
//10.1 Define point type
struct Point {
    int x;
    int y;
};
//10.2:Read from the user
istream& operator>>(istream& is, Point& p)
{
    char ch1;
    if (is >> ch1 && ch1 != '(') {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    char ch2;
    char ch3;
    int xpoint;
    int ypoint;
    is >> xpoint >> ch2 >> ypoint >> ch3;
    if (!is || ch3 != ')') {
        if (is.eof()) return is;
        error("bad point");
    }
    p.x = xpoint;
    p.y = ypoint;
    return is;
}
//10.3 Output to the terminal
ostream& operator<<(ostream& os, Point& p)
{
    return os << '(' << p.x << ',' << p.y << ')';
}

void read_from_file(vector<Point>& points, string& name)
{
    ifstream ist {name};
    ist.exceptions(ist.exceptions()|ios_base::badbit);

    if (!ist) error("can't open input file ", name);
    for (Point p; ist >> p; )
        points.push_back(p);
}

int main()
try {
    cout << "Please enter seven points";
    vector<Point> original_points;

    while (original_points.size() < 7) {
        Point p;
        cin >> p;
        original_points.push_back(p);
    } 

    for (int i = 0;i<original_points.size();i++)
        cout << original_points.at(i)<<'\n';
//10.4:open ofstream
    string fname = "mydata.txt";
    ofstream ost (fname);
    if (!ost) error("could not open file ", fname);

    for (int i = 0;i<original_points.size();i++){
        ost << original_points.at(i);
        }
        //10.5:Close ofstream
    ost.close();

    vector<Point> processed_points;
    
    read_from_file(processed_points, fname);
//10.6:read from the text and output
    for (int i = 0;i<processed_points.size();i++){
    cout<<processed_points.at(i)<<'\n';
    }
//10.7:Check for the right size
    if (original_points.size() != processed_points.size())
        cout << "Something's wrong!\n";
}
catch (exception& e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
