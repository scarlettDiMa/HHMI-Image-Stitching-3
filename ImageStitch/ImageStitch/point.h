#ifndef POINT_H
#define POINT_H

class Point
{
public:
	Point( ) { x = 0; y = 0; }
	Point( const Point& pIn ) { x = pIn.x; y = pIn.y; }
	Point( int xIn, int yIn ) { x = xIn; y = yIn; }
	void set( int xIn, int yIn ) { x = xIn; y = yIn; }
	const Point& operator=( const Point& pIn ) { x = pIn.x; y = pIn.y; return *this; }
	Point operator+=( const Point& pIn ) { x += pIn.x; y += pIn.y; return *this; }
	Point operator-=( const Point& pIn ) { x -= pIn.x; y -= pIn.y; return *this; }
	bool operator<( const Point& pIn ) { if ( this->x < pIn.x && this->y < pIn.y ) return true; return false; }
	bool operator>( const Point& pIn ) { if ( this->x > pIn.x && this->y > pIn.y ) return true;	return false; }
	bool operator<=( const Point& pIn ) { if ( this->x <= pIn.x && this->y <= pIn.y ) return true; return false; }
	bool operator>=( const Point& pIn ) { if ( this->x >= pIn.x && this->y >= pIn.y ) return true; return false; }
	bool operator==( const Point& pIn ) { if ( this->x == pIn.x && this->y == pIn.y ) return true; return false; }

	Point operator+( const Point& pIn )  { Point ret( x + pIn.x, y + pIn.y); return ret; }
	Point operator-( const Point& pIn )  { Point ret( x - pIn.x, y - pIn.y); return ret; }

	int x;
	int y;
};

#endif POINT_H