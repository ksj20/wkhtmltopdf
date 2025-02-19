#pragma once

// Copyright 2010-2020 wkhtmltopdf authors
// Copyright 2023 Odoo S.A.
//
// This file is part of wkhtmltopdf.
//
// wkhtmltopdf is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// wkhtmltopdf is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with wkhtmltopdf.  If not, see <http://www.gnu.org/licenses/>.

#include <QString>

#include "loadsettings.hh"
#include "logging.hh"
#include "websettings.hh"

namespace wkhtmltopdf {
namespace settings {

/*! \brief Settings for cropping image */
struct CropSettings {
	//! Cropping left/x coord
	int left = -1;
	//! Cropping top/y coord
	int top = -1;
	//! Cropping width/w dime
	int width = -1;
	//! Cropping height/h dime
	int height = -1;
};

/*! \brief Class holding all user settings.

	This class holds all the user settings, settings can be filled in by hand,
	or with other methods.
	\sa CommandLineParser::parse()
*/
struct ImageGlobal {
	ImageGlobal();

	//! Crop related settings
	CropSettings crop;
	//! Scale related settings
	// ScaleSettings scale;

	LoadGlobal loadGlobal;
	LoadPage loadPage;
	Web web;

	//! Log level
	LogLevel logLevel;

	bool transparent;

	//! Should we use the graphics system
	bool useGraphics;

	QString in;
	//! The file for output
	QString out;
	//! The output format
	QString fmt;

	//! Set the screen width
	int screenWidth;

	//! Set the screen height
	int screenHeight;

	//! Image Quality
	int quality;

	bool smartWidth;

	QString get(const char * name);
	bool set(const char * name, const QString & value);
};

} // namespace settings
} // namespace wkhtmltopdf
