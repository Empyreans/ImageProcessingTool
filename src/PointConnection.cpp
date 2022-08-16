#include "PointConnection.h"
#include "PointDistribution.h"

PointConnectionResult PointConnection::calculate(const PointDistributionResult & pointDistributionResult, const BaseImage & _baseImage, const PointConnectionSettings & _pointConnectionSettings)
{
	ofMesh triangleMesh;

	PointConnectionType pointConnectionType = _pointConnectionSettings.pointConnectionType;
	bool colorMode = _pointConnectionSettings.colorMode;

	switch (_pointConnectionSettings.pointConnectionType) {
	case PointConnectionType::Delaunay:
		BaseImage baseImage = _baseImage;
		std::vector<CDT::V2d<float>> verts = pointDistributionResult.getCdtPoints();

		CDT::Triangulation<float> cdt;

		CDT::RemoveDuplicates(verts);
		cdt.insertVertices(verts);
		cdt.eraseSuperTriangle();

		triangleMesh.clear();
		triangleMesh.setMode(OF_PRIMITIVE_TRIANGLES);

		for (int i = 0; i < cdt.vertices.size(); i++) {
			float x = cdt.vertices[i].x;
			float y = cdt.vertices[i].y;
			triangleMesh.addVertex(ofVec3f(x, y, 0.0));
			if (colorMode) {
				triangleMesh.addColor(baseImage.getColorAt(x, y));
			}
		}

		for (int i = 0; i < cdt.triangles.size(); i++) {
			triangleMesh.addIndex(cdt.triangles[i].vertices[0]);
			triangleMesh.addIndex(cdt.triangles[i].vertices[1]);
			triangleMesh.addIndex(cdt.triangles[i].vertices[2]);
		}
	}
	return PointConnectionResult(triangleMesh);
}

void PointConnectionResult::draw() {
	ofNoFill();
	ofSetLineWidth(1.0);
	triangleMesh.drawWireframe();
}