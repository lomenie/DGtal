#pragma once

/**
 * @file DigitalSetSelector.h
 * @author Jacques-Olivier Lachaud (\c jacques-olivier.lachaud@univ-savoie.fr )
 * Laboratory of Mathematics (CNRS, UMR 5807), University of Savoie, France
 *
 * @author Sebastien Fourey (\c Sebastien.Fourey@greyc.ensicaen.fr )
 * Groupe de Recherche en Informatique, Image, Automatique et
 * Instrumentation de Caen - GREYC (CNRS, UMR 6072), ENSICAEN, France
 *
 * @date 2010/07/01
 *
 * Header file for module DigitalSetSelector.cpp
 *
 * This file is part of the DGtal library.
 */

#if defined(DigitalSetSelector_RECURSES)
#error Recursive header files inclusion detected in DigitalSetSelector.h
#else // defined(DigitalSetSelector_RECURSES)
/** Prevents recursive inclusion of headers. */
#define DigitalSetSelector_RECURSES

#if !defined DigitalSetSelector_h
/** Prevents repeated inclusion of headers. */
#define DigitalSetSelector_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include "DGtal/base/Common.h"
//////////////////////////////////////////////////////////////////////////////

namespace DGtal
{

  /////////////////////////////////////////////////////////////////////////////
  // template class DigitalSetSelector
  /**
   * Description of template class 'DigitalSetSelector' <p>
   * \brief Aim:
   */
  template <typename Domain, uint Preferences >
  struct DigitalSetSelector
  {
    // ----------------------- Local types ------------------------------
    
    enum Size { SMALL = 0, MEDIUM = 1, BIG = 2, WHOLE = 3 };
    enum Variability { LOW_VAR = 0, HIGH_VAR = 4 };
    enum Iterability { LOW_ITER = 0, HIGH_ITER = 8 };
    enum BelongTestability { LOW_BEL = 0, HIGH_BEL = 16 };

    /**
     * Adequate digital set representation for the given preferences.
     */
    typedef DigitalSetBySTLSet<Domain> Type;

    // ----------------------- Standard services ------------------------------
  public:

    /**
     * Destructor.
     */
    ~DigitalSetSelector();

    // ----------------------- Interface --------------------------------------
  public:

    /**
     * Writes/Displays the object on an output stream.
     * @param out the output stream where the object is written.
     */
    void selfDisplay ( std::ostream & out ) const;

    /**
     * Checks the validity/consistency of the object.
     * @return 'true' if the object is valid, 'false' otherwise.
     */
    bool isValid() const;

    // ------------------------- Protected Datas ------------------------------
  private:
    // ------------------------- Private Datas --------------------------------
  private:

    // ------------------------- Hidden services ------------------------------
  protected:

    /**
     * Constructor.
     * Forbidden by default (protected to avoid g++ warnings).
     */
    DigitalSetSelector();

  private:

    /**
     * Copy constructor.
     * @param other the object to clone.
     * Forbidden by default.
     */
    DigitalSetSelector ( const DigitalSetSelector & other );

    /**
     * Assignment.
     * @param other the object to copy.
     * @return a reference on 'this'.
     * Forbidden by default.
     */
    DigitalSetSelector & operator= ( const DigitalSetSelector & other );

    // ------------------------- Internals ------------------------------------
  private:

  }; // end of class DigitalSetSelector


  /**
   * Overloads 'operator<<' for displaying objects of class 'DigitalSetSelector'.
   * @param out the output stream where the object is written.
   * @param object the object of class 'DigitalSetSelector' to write.
   * @return the output stream after the writing.
   */
  template <typename T>
  std::ostream&
  operator<< ( std::ostream & out, const DigitalSetSelector<T> & object );

} // namespace DGtal


///////////////////////////////////////////////////////////////////////////////
// Includes inline functions.
#include "DGtal/kernel/sets/DigitalSetSelector.ih"

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#endif // !defined DigitalSetSelector_h

#undef DigitalSetSelector_RECURSES
#endif // else defined(DigitalSetSelector_RECURSES)