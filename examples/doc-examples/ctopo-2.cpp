/**
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 **/

/**
 * @file ctopo-2.cpp
 * @ingroup Examples
 * @author Bertrand Kerautret (\c kerautre@loria.fr )
 * LORIA (CNRS, UMR 7503), University of Nancy, France
 *
 * @date 2011/04/28
 *
 * An example file named ctopo-2.
 *
 * This file is part of the DGtal library.
 */

///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "DGtal/base/Common.h"
#include "DGtal/topology/KhalimskySpaceND.h"
#include "DGtal/kernel/imagesSetsUtils/SetFromImage.h"
#include "DGtal/kernel/images/ImageSelector.h"
#include "DGtal/helpers/StdDefs.h"
#include "DGtal/helpers/Surfaces.h"

#include "DGtal/io/readers/PNMReader.h"
#include "DGtal/io/colormaps/GradientColorMap.h"
#include "ConfigExamples.h"




///////////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace DGtal;

///////////////////////////////////////////////////////////////////////////////

int main( int argc, char** argv )
{
  typedef ImageSelector < Z2i::Domain, int>::Type Image;
  std::string inputFilename = examplesPath + "samples/circleR10modif.pgm"; 
  Image image = PNMReader<Image>::importPGMImage( inputFilename ); 
  
  Z2i::DigitalSet set2d (image.domain());
  SetFromImage<Z2i::DigitalSet>::append<Image>(set2d, image, 0, 255);
  DGtalBoard board;
  board << image.domain() << set2d; // display domain and set


  // Construct the Khalimsky space from the image domain
  Z2i::KSpace ks;
  bool space_ok = ks.init( image.domain().lowerBound(), image.domain().upperBound(), true );

  //Extract a boundary cell
  Z2i::SCell aCell = Surfaces<Z2i::KSpace>::findABel(ks, set2d);

  // Getting the consecutive surfels of the 2D boundary
  std::vector<Z2i::SCell> vectBdrySCell;
  SurfelAdjacency<2> SAdj( true );
  Surfaces<Z2i::KSpace>::track2DBoundary( vectBdrySCell,
					  ks, SAdj, set2d, aCell );

  board << CustomStyle( (*(vectBdrySCell.begin())).styleName(), 
			new CustomColors(  DGtalBoard::Color( 255, 255, 0 ),
					   DGtalBoard::Color( 192, 192, 0 ) ));
  
  GradientColorMap<int> cmap_grad( 0, vectBdrySCell.size() );
  cmap_grad.addColor( DGtalBoard::Color( 50, 50, 255 ) );
  cmap_grad.addColor( DGtalBoard::Color( 255, 0, 0 ) );
  cmap_grad.addColor( DGtalBoard::Color( 255, 255, 10 ) );

  uint d=0;
  std::vector<Z2i::SCell>::iterator it;
  for ( it=vectBdrySCell.begin() ; it != vectBdrySCell.end(); it++ ){
    board<< CustomStyle((*it).styleName() ,
			new CustomColors( DGtalBoard::Color::Black,
					  cmap_grad( d )))<< *it;
    d++;
  }

    board << CustomStyle( aCell.styleName(), new CustomColors(  DGtalBoard::Color( 255, 0, 0 ),
								DGtalBoard::Color( 192, 0, 0 ) ));
    board << aCell;  
    board.saveEPS( "ctopo-2.eps");
    board.saveFIG( "ctopo-2.fig");
    
    return 0;
}
//                                                                           //
///////////////////////////////////////////////////////////////////////////////