#ifndef stuff_h
#define stuff_h

class square
{
	public:
		float width;
		float height;
		float area()
		{
			return width*height;
		}
		square()
		{
			width=0;
			height=0;
		}
		square(float w)
		{
			width=w;
			height=w;
		}
		square(float w, float h)
		{
			width=w;
			height=h;
		}
		~square()
		{
			std::cout<<"DESTROYED";
		}
};

class box: public square
{
	public:
		float depth;
		float area()
		{
			return width*height*depth;
		}
};

#endif