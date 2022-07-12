#include "PointConnection.h"
#include "PointDistribution.h"

PointConnectionResult PointConnection::calculate(const PointDistributionResult & pointDistributionResult, const PointConnectionSettings & _pointConnectionSettings)
{
	ofMesh triangleMesh;

	switch (_pointConnectionSettings.pointConnectionType) {
	case PointConnectionType::Delaunay:
		// calculate cdt 
		CDT::Triangulation<float> cdt;
		cdt.insertVertices(pointDistributionResult.getCdtPoints());
		cdt.eraseSuperTriangle();

		// cdt to ofMesh conversion
		triangleMesh.clear();
		triangleMesh.setMode(OF_PRIMITIVE_TRIANGLES);

		for (int i = 0; i < cdt.vertices.size(); i++) {
			triangleMesh.addVertex(ofVec3f(cdt.vertices[i].x, cdt.vertices[i].y, 0.0));
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