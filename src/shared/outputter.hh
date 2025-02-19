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
#include <QVector>
#include <cstdio>

#include "commandlineparserbase.hh"

class Outputter {
  public:
	virtual ~Outputter() {}
	virtual void beginSection(const QString & name) = 0;
	virtual void endSection() = 0;
	virtual void beginParagraph() = 0;
	virtual void text(const QString & t) = 0;
	virtual void bold(const QString & t) = 0;
	virtual void italic(const QString & t) = 0;
	virtual void link(const QString & l) = 0;
	virtual void sectionLink(const QString & s) = 0;
	virtual void endParagraph() = 0;
	virtual void verbatim(const QString & t) = 0;
	virtual void beginList(bool ordered = false) = 0;
	virtual void endList() = 0;
	virtual void listItem(const QString & t) = 0;
	virtual void beginSwitch() = 0;
	virtual void cswitch(const ArgHandler * h) = 0;
	virtual void endSwitch() = 0;
	void paragraph(const QString & t);
	static Outputter * text(FILE * fd, bool doc = false, bool extended = false);
	static Outputter * man(FILE * fd);
	static Outputter * html(FILE * fd);
};
