/**********************************************************************
 *  Copyright (c) 2008-2013, Alliance for Sustainable Energy.
 *  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 **********************************************************************/

#include <energyplus/ReverseTranslator.hpp>
#include <model/ZoneAirHeatBalanceAlgorithm.hpp>
#include <model/ZoneAirHeatBalanceAlgorithm_Impl.hpp>
#include <utilities/idd/ZoneAirHeatBalanceAlgorithm_FieldEnums.hxx>
#include <utilities/idd/OS_ZoneAirHeatBalanceAlgorithm_FieldEnums.hxx>
#include <utilities/idd/IddEnums.hxx>

using namespace openstudio::model;

namespace openstudio {

namespace energyplus {

OptionalModelObject ReverseTranslator::translateZoneAirHeatBalanceAlgorithm( const WorkspaceObject & workspaceObject )
{
  if( workspaceObject.iddObject().type() != IddObjectType::ZoneAirHeatBalanceAlgorithm )
  {
     LOG(Error, "WorkspaceObject is not IddObjectType: ZoneAirHeatBalanceAlgorithm");
     return boost::none;
  }

  ZoneAirHeatBalanceAlgorithm mo = m_model.getUniqueModelObject<ZoneAirHeatBalanceAlgorithm>();

  boost::optional<std::string> s = workspaceObject.getString(ZoneAirHeatBalanceAlgorithmFields::Algorithm);
  if( s )
  {
    mo.setString(OS_ZoneAirHeatBalanceAlgorithmFields::Algorithm,s.get());
  }

  return mo;
}

} // energyplus

} // openstudio

