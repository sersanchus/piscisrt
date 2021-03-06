//---------------------------------------------------------------------------//
//                                                                           //
// PiscisRT (Piscis Ray Tracer)                                              //
//                                                                           //
// Copyright (C) 2003  Sergio Sancho Chust                                   //
//                                                                           //
// This program is free software; you can redistribute it and/or modify      //
// it under the terms of the GNU General Public License as published by      //
// the Free Software Foundation; either version 2 of the License, or         //
// (at your option) any later version.                                       //
//                                                                           //
// This program is distributed in the hope that it will be useful,           //
// but WITHOUT ANY WARRANTY; without even the implied warranty of            //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             //
// GNU General Public License for more details.                              //
//                                                                           //
// You should have received a copy of the GNU General Public License         //
// along with this program; if not, write to the Free Software               //
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA //
//                                                                           //
// Contact with sergiosancho@terra.es                                        //
//                                                                           //
// Almazora-Castellón-Spain                                                  //
//                                                                           //
//---------------------------------------------------------------------------//

#ifndef __PRTPOINTLIGHT_H__
#define __PRTPOINTLIGHT_H__

#include "PRTUtil.h"
#include "PRTVector.h"
#include "PRTLight.h"

//--------------------------------------------------------------------------------------
//! The PRTPointLight class.
/*!	This class represents a point light.*/
//--------------------------------------------------------------------------------------

class PISCISRT_API PRTPointLight : public PRTLight
{

public:

	PRTVector pos; 		//!< The position of the light.

//--------------------------------------------------------------------------------------

	//!	A constructor of the PRTPointLight.
	/*!	
		\param point position of the light
		\param color color
	*/
	PRTPointLight(const PRTVector &point,const PRTVector &color);

//--------------------------------------------------------------------------------------

	//!	Computes what point light represents the PRTPointLight at a given position.
	/*!	
		\param point point on 3d
		\return the position of the point light
	*/
	PRTVector ComputeWhatPointLight(PRTVector &point);

//--------------------------------------------------------------------------------------

	//!	Computes the light ray. What light intensity is seen by the ray.
	/*!	
		\param ray the ray
		\param ipoint intersected point
		\param normal normal at that point
		\param object object to discard
		\param main pointer to the global PRTMain
		\return the intensity
	*/
	PRTVector ComputeLightRay(PRTRay &ray, PRTIntersectPoint &ipoint, PRTVector &normal, const PRTObject *object, PRTMain *main);

//--------------------------------------------------------------------------------------

};

#endif
