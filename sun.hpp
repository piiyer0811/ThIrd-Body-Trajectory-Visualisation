#pragma once

#include "crtbp.hpp"

#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>

/// <summary>
/// Class that represents the sun.
/// </summary>
class Sun
{
public:
	/// <summary>
	/// Constructor.
	/// </summary>
	Sun()
	{
		// Create a sphere with texture coordinates
		const double sphere_radius = 0.1;
		vtkNew<vtkSphereSource> sphereSource;
		sphereSource->SetRadius(sphere_radius);
		sphereSource->SetPhiResolution(100);
		sphereSource->SetThetaResolution(100);
		vtkNew<vtkPolyDataMapper> polyMapper;
		polyMapper->SetInputConnection(sphereSource->GetOutputPort());

		// create actor
		mActor = vtkSmartPointer<vtkActor>::New();
		mActor->SetMapper(polyMapper);
		mActor->SetPosition(CRTBP::Sun().x(), CRTBP::Sun().y(), 0);
	}

	/// <summary>
	/// Adds the actors to the renderer.
	/// </summary>
	/// <param name="renderer">Renderer to add the actors to.</param>
	void InitRenderer(vtkSmartPointer<vtkRenderer> renderer)
	{
		renderer->AddActor(mActor);
	}

private:
	Sun(const Sun&) = delete;				// Delete the copy-constructor.
	void operator=(const Sun&) = delete;	// Delete the assignment operator.

	vtkSmartPointer<vtkActor> mActor;		// Actor that represents the sun geometry.
};