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

#ifndef __PRTLINE_H__
#define __PRTLINE_H__

#include "PRTUtil.h"
#include "PRTObject.h"
#include "PRTVector.h"
#include "PRTTexCoord.h"
#include "PRTMaterial.h"

//--------------------------------------------------------------------------------------
//! The PRTLine class.
/*!	This class represents a line in 3d.*/
//--------------------------------------------------------------------------------------

class PISCISRT_API PRTLine : public PRTObject
{

private:

	PRTVector p1;			//!< The first point on the line.
	PRTVector p2;			//!< The second point on the line.
	PRTVector n1;			//!< The normal of the first point on the line.
	PRTVector n2;			//!< The normal of the second point on the line.
	PRTVector c1;			//!< The color of the first point on the line.
	PRTVector c2;			//!< The color of the second point on the line.
	PRTTexCoord t1;			//!< The texture coordinates of the first point on the line.
	PRTTexCoord t2;			//!< The texture coordinates of the second point on the line.
	
public:
	
//--------------------------------------------------------------------------------------

	//!	A constructor of the PRTLine.
	/*!	
		\param p1
		\param p2
		\param n1
		\param n2
		\param material of the PRTLine
	*/
	PRTLine(PRTVector p1,PRTVector p2,PRTVector n1,PRTVector n2,PRTMaterial *material);

//--------------------------------------------------------------------------------------

	//!	Another constructor of the PRTLine.
	/*!	
		\param p1
		\param p2
		\param n1
		\param n2
		\param c1
		\param c2
		\param material of the PRTLine
	*/
	PRTLine(PRTVector p1,PRTVector p2,PRTVector n1,PRTVector n2,PRTVector c1,PRTVector c2,PRTMaterial *material);

//--------------------------------------------------------------------------------------

	//!	Another constructor of the PRTLine.
	/*!	
		\param p1
		\param p2
		\param n1
		\param n2
		\param t1
		\param t2
		\param material of the PRTTriangle
	*/
	PRTLine(PRTVector p1,PRTVector p2,PRTVector n1,PRTVector n2,PRTTexCoord t1,PRTTexCoord t2,PRTMaterial *material);
	
//--------------------------------------------------------------------------------------
	
	//!	Computes a texture coordinates for a point on 3d.
	/*!	
		\param point on 3d
		\return the texture coordinates
	*/
	PRTTexCoord ComputeTexCoord(PRTVector point);

//--------------------------------------------------------------------------------------
	
	//!	Computes a point in 3d for a texture coordinates.
	/*!	
		\param texcoord texture coordinates
		\return PRTVector the point in 3d
	*/
	PRTVector ComputePoint(PRTTexCoord texcoord);
	
//--------------------------------------------------------------------------------------
	
	//!	Computes a normal for a point on 3d.
	/*!	
		\param point on 3d
		\return PRTVector the normal on the PRTLine
	*/
	PRTVector ComputeNormal(PRTVector point);

//--------------------------------------------------------------------------------------
	
	//!	Computes a tangent vector for a point on 3d.
	/*!	
		\param point on 3d
		\return PRTVector the tangent on the PRTLine
	*/
	PRTVector ComputeTangent(PRTVector point);

//--------------------------------------------------------------------------------------
	
	//!	Computes a binormal vector for a point on 3d.
	/*!	
		\param point on 3d
		\return PRTVector the binormal on the PRTLine
	*/
	PRTVector ComputeBinormal(PRTVector point);

//--------------------------------------------------------------------------------------
	
	//!	Computes a color for a point on 3d.
	/*!	
		\param point on 3d
		\return PRTVector the color for the point
	*/
	PRTVector ComputeColor(PRTVector point);

//--------------------------------------------------------------------------------------
	
	//!	Computes the intersection of the PRTLine with a PRTRay.
	/*!	
		\param ray for intersection
		\param doublesided forced or not
		\return PRTIntersectPoint the point of intersection if any
	*/
	bool ComputeIntersection(const PRTRay& ray,bool doublesided, PRTIntersectPoint& result);

//--------------------------------------------------------------------------------------

};

#endif
