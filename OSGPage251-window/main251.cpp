// -- Exempel sidan 251
// 1
#include <osg/GraphicsContext>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>

int main(void) 
{

	// 2
	osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;

	traits->x = 50;
	traits->y = 50;
	traits->width  = 800;
	traits->height = 600;
	traits->windowDecoration = true;

	traits->doubleBuffer = true;
	traits->samples = 4;

	// 3
	osg::ref_ptr<osg::GraphicsContext> gc = osg::GraphicsContext::createGraphicsContext(traits.get());

	// 4
	osg::ref_ptr<osg::Camera> camera = new osg::Camera;

	camera->setGraphicsContext(gc);
	camera->setViewport(new osg::Viewport(0, 0, traits->width/1.0, traits->height/1.0));
	camera->setClearMask( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT );
	camera->setClearColor(osg::Vec4f(0.2f, 0.2f, 0.4f, 1.0f));
	camera->setProjectionMatrixAsPerspective(30.0f, (double)traits->width/(double)traits->height, 107.0, 112.0 );

	// 5  -- load model
	osg::ref_ptr<osg::Node> root = osgDB::readNodeFile("E:\\6.Testdata\\3D\\osg\\cessnafire.osg.0,0,0.rot");
	osgViewer::Viewer viewer;
	viewer.setCamera(camera.get());

	// By default, OSG automatically computes the near and far planes based on the scenegraph geometry
	//viewer.getCamera()->setComputeNearFarMode(osg::CullSettings::DO_NOT_COMPUTE_NEAR_FAR);
	viewer.setSceneData(root.get());

	return viewer.run();

}
