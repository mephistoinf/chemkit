/******************************************************************************
**
** Copyright (C) 2009-2011 Kyle Lutz <kyle.r.lutz@gmail.com>
** All rights reserved.
**
** This file is a part of the chemkit project. For more information
** see <http://www.chemkit.org>.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions
** are met:
**
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in the
**     documentation and/or other materials provided with the distribution.
**   * Neither the name of the chemkit project nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
******************************************************************************/

#ifndef CHEMKIT_FORCEFIELDENERGYDESCRIPTOR_INLINE_H
#define CHEMKIT_FORCEFIELDENERGYDESCRIPTOR_INLINE_H

#include "forcefieldenergydescriptor.h"

#include "forcefield.h"

namespace chemkit {

// === ForceFieldEnergyDescriptor ========================================== //
/// \class ForceFieldEnergyDescriptor forcefieldenergydescriptor.h chemkit/forcefieldenergydescriptor.h
/// \ingroup chemkit-md
/// \internal
/// \brief The ForceFieldEnergyDescriptor class provides a molecular
///        descriptor for force field energy.

// --- Construction and Destruction ---------------------------------------- //
/// Creates a new force field energy descriptor with \p name.
template<typename ForceField>
ForceFieldEnergyDescriptor<ForceField>::ForceFieldEnergyDescriptor(const std::string &name)
    : MolecularDescriptor(name)
{
}

/// Destroys the force field energy descriptor object.
template<typename ForceField>
ForceFieldEnergyDescriptor<ForceField>::~ForceFieldEnergyDescriptor()
{
}

// --- Descriptor ---------------------------------------------------------- //
/// Returns the energy value for \p molecule.
template<typename ForceField>
Variant ForceFieldEnergyDescriptor<ForceField>::value(const Molecule *molecule) const
{
    ForceField forceField;
    forceField.addMolecule(molecule);

    bool ok = forceField.setup();
    if(!ok){
        return Variant();
    }

    return forceField.energy();
}

} // end chemkit namespace

#endif // CHEMKIT_FORCEFIELDENERGYDESCRIPTOR_INLINE_H