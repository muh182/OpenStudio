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

#include "Buttons.hpp"
#include <QString>

namespace openstudio {

GrayButton::GrayButton(QWidget * parent)
  : QPushButton()
{
  setFlat(true);

  QString style;
  style.append("QPushButton { ");
  style.append("border-radius: 4px; ");
  style.append("border: 1px solid #949393; ");
  style.append("background: qlineargradient(x1:0,y1:0,x2:0,y2:1, ");
  style.append("                             stop: 0 #F2F2F2, "); 
  style.append("                             stop: 1 #A5A5A5 ); ");
  style.append("height: 22px; ");
  style.append("font-size: 12px; ");
  style.append("margin: 0; ");
  style.append("padding-left: 10px; ");
  style.append("padding-right: 10px; ");
  style.append("} ");

  style.append("QPushButton:pressed { ");
  style.append("background: qlineargradient(x1:0,y1:0,x2:0,y2:1, ");
  style.append("                             stop: 0 #262626, "); 
  style.append("                             stop: 1 #535353 ); ");
  style.append("color: white; ");
  style.append("} ");

  style.append("QPushButton:checked { ");
  style.append("background: qlineargradient(x1:0,y1:0,x2:0,y2:1, ");
  style.append("                             stop: 0 #262626, "); 
  style.append("                             stop: 1 #535353 ); ");
  style.append("color: white; ");
  style.append("} ");

  setStyleSheet(style);
}

BlueButton::BlueButton(QWidget * parent)
  : QPushButton()
{
  setFlat(true);

  QString style;
  style.append("QPushButton { ");
  style.append("border-radius: 4px; ");
  style.append("border: 1px solid #093A07; ");
  style.append("background: qlineargradient(x1:0,y1:0,x2:0,y2:1, ");
  style.append("                             stop: 0 #C8DAF1, "); 
  style.append("                             stop: 1 #39679E ); ");
  style.append("height: 22px; ");
  style.append("font-size: 12px; ");
  style.append("margin: 0; ");
  style.append("padding-left: 10px; ");
  style.append("padding-right: 10px; ");
  style.append("} ");

  style.append("QPushButton:pressed { ");
  style.append("background: qlineargradient(x1:0,y1:0,x2:0,y2:1, ");
  style.append("                             stop: 0 #262626, "); 
  style.append("                             stop: 1 #535353 ); ");
  style.append("color: white; ");
  style.append("} ");

  style.append("QPushButton:checked { ");
  style.append("background: qlineargradient(x1:0,y1:0,x2:0,y2:1, ");
  style.append("                             stop: 0 #262626, "); 
  style.append("                             stop: 1 #535353 ); ");
  style.append("color: white; ");
  style.append("} ");

  setStyleSheet(style);
}

SofterRemoveButton::SofterRemoveButton(QWidget * parent)
  : QPushButton()
{
  setFlat(true);

  setFixedSize(16,16);

  QString style;
  style.append("QPushButton {"
               "  background-image:url(':/shared_gui_components/images/delete_softer.png');"
               "  border:none;"
               "}");
  style.append("QPushButton:hover {"
               "  background-image:url(':/shared_gui_components/images/delete_softer_over.png');"
               "}");
  style.append("QPushButton:pressed {"
               "  background-image:url(':/shared_gui_components/images/delete_softer_press.png');"
               "}");

  setStyleSheet(style);
}

AddScriptButton::AddScriptButton(QWidget * parent)
  : QPushButton()
{
  setFlat(true);

  setFixedSize(24,24);

  QString style;
  style.append("QPushButton {"
               "  background-image:url(':/shared_gui_components/images/add_script_icon.png');"
               "  border:none;"
               "}");
  style.append("QPushButton:hover {"
               "  background-image:url(':/shared_gui_components/images/add_script_icon_over.png');"
               "}");
  style.append("QPushButton:pressed {"
               "  background-image:url(':/shared_gui_components/images/add_script_icon_press.png');"
               "}");

  setStyleSheet(style);
}

DuplicateButton::DuplicateButton(QWidget * parent)
  : QPushButton()
{
  setFlat(true);

  setFixedSize(24,24);

  QString style;
  style.append("QPushButton {"
               "  background-image:url(':/shared_gui_components/images/duplicate_off.png');"
               "  border:none;"
               "}");
  style.append("QPushButton:hover {"
               "  background-image:url(':/shared_gui_components/images/duplicate_over.png');"
               "}");
  style.append("QPushButton:pressed {"
               "  background-image:url(':/shared_gui_components/images/duplicate_press.png');"
               "}");
  style.append("QPushButton:disabled {"
               "  background-image:url(':/shared_gui_components/images/duplicate_disabled.png');"
               "}");

  setStyleSheet(style);
}

UpButton::UpButton(QWidget * parent)
  : QPushButton(parent)
{
  setFlat(true);

  setFixedSize(22,24);

  QString style;

  style.append("QPushButton {"
               "  background-image:url(':/shared_gui_components/images/arrow_up.png');"
               "  border:none;"
               "}");
  style.append("QPushButton:hover {"
               "  background-image:url(':/shared_gui_components/images/arrow_up_over.png');"
               "}");
  style.append("QPushButton:pressed {"
               "  background-image:url(':/shared_gui_components/images/arrow_up_press.png');"
               "}");

  setStyleSheet(style);
}

DownButton::DownButton(QWidget * parent)
  : QPushButton(parent)
{
  setFlat(true);

  setFixedSize(22,24);

  QString style;

  style.append("QPushButton {"
               "  background-image:url(':/shared_gui_components/images/arrow_down.png');"
               "  border:none;"
               "}");
  style.append("QPushButton:hover {"
               "  background-image:url(':/shared_gui_components/images/arrow_down_over.png');"
               "}");
  style.append("QPushButton:pressed {"
               "  background-image:url(':/shared_gui_components/images/arrow_down_press.png');"
               "}");

  setStyleSheet(style);
}

MyMeasuresFolderButton::MyMeasuresFolderButton(QWidget * parent)
  : QPushButton(parent)
{
  setFlat(true);

  setFixedSize(31,24);

  QString style;

  style.append("QPushButton {"
               "  background-image:url(':/shared_gui_components/images/open_my_measures.png');"
               "  border:none;"
               "}");
  style.append("QPushButton:pressed {"
               "  background-image:url(':/shared_gui_components/images/open_my_measures_press.png');"
               "}");

  setStyleSheet(style);
}

OpenDirectoryButton::OpenDirectoryButton(QWidget * parent)
  : QPushButton(parent)
{
  setFlat(true);

  setFixedSize(31,24);

  QString style;

  style.append("QPushButton {"
               "  background-image:url(':/shared_gui_components/images/dir.png');"
               "  border:none;"
               "}");
  style.append("QPushButton:pressed {"
               "  background-image:url(':/shared_gui_components/images/dir_press.png');"
               "}");
  style.append("QPushButton:disabled {"
               "  background-image:url(':/shared_gui_components/images/dir_disabled.png');"
               "}");

  setStyleSheet(style);
}

CreateOneWithSelectedMeasuresButton::CreateOneWithSelectedMeasuresButton()
  : GrayButton()
{
  setText("Create One With Selected Measures");
}

CreateOneForEachSelectedMeasureButton::CreateOneForEachSelectedMeasureButton()
  : GrayButton()
{
  setText("Create One For Each Selected Measure");
}

CreateFromFileButton::CreateFromFileButton()
  : GrayButton()
{
  setText("Create From External File");
}

PlayButton::PlayButton(QWidget * parent)
  : QPushButton(parent)
{
  setFlat(true);

  QString style;

  style.append("QPushButton {"
               "  background-color:transparent;"
               "  background-image:url(':/shared_gui_components/images/run_simulation_button.png');"
               "  background-position:right;"
               "  background-repeat:none;"
               "  border:none;"
               "  font:bold 13px;"
               "  height:35px;"
               "  text-align:left;"
               "}");
  style.append("QPushButton:hover {"
               "  background-image:url(':/shared_gui_components/images/run_simulation_over.png');"
               "}");
  style.append("QPushButton:pressed {"
               "  background-image:url(':/shared_gui_components/images/run_simulation_press.png');"
               "}");

  // pause button
  /*
  style.append("QPushButton:checked {"
               "  background-image:url(':/shared_gui_components/images/pause_regular.png');"
               "}");
  style.append("QPushButton:checked:hover {"
               "  background-image:url(':/shared_gui_components/images/pause_over.png');"
               "}");
  style.append("QPushButton:checked:pressed {"
               "  background-image:url(':/shared_gui_components/images/pause_press.png');"
               "}");
  */

  // stop button
  style.append("QPushButton:checked {"
               "  background-image:url(':/shared_gui_components/images/run_cancel.png');"
               "}");
  style.append("QPushButton:checked:hover {"
               "  background-image:url(':/shared_gui_components/images/run_cancel_over.png');"
               "}");
  style.append("QPushButton:checked:pressed {"
               "  background-image:url(':/shared_gui_components/images/run_cancel_press.png');"
               "}");

  setStyleSheet(style);
}


} // openstudio

