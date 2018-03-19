#include <iostream>
#include <cstring>
#include <pcl/point_cloud.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/io/pcd_io.h>


using namespace std;
class foo
{

	static int count ;
public:
	foo()
	{

		count++;
	}

	int getfoo()
	{
		return count;
	}
};

int foo::count = 0;

int main(int argc, char const *argv[])
{

	foo f1,f2,f3;
	pcl::PointCloud<pcl::PointXYZ> cloud;
	cout<<f1.getfoo()<<" "<<f2.getfoo()<<" "<<f3.getfoo();
	return 0;
}