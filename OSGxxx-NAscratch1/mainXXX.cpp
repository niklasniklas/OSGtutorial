#include <osgDB/ReadFile>
#include <osgViewer/Viewer>

int main(void)
{

	// Niclas scratchpad

	//osg::ref_ptr<osg::Node> root;
	osgViewer::Viewer viewer;
	viewer.setSceneData(osgDB::readNodeFile("E:\\6.Testdata\\3D\\osg\\cessna.osg"));
	return viewer.run();

}

