/*
    EIBD eib bus access and management daemon
    Copyright (C) 2005-2011 Martin Koegler <mkoegler@auto.tuwien.ac.at>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "emi1.h"
#include "emi.h"

EMI1Driver::~EMI1Driver()
{
}

void
EMI1Driver::cmdEnterMonitor()
{
  const uchar t[] = { 0x46, 0x01, 0x00, 0x60, 0x90 };
  // pth_usleep (1000000);
  iface->send_Local (CArray (t, sizeof (t)));
}

void
EMI1Driver::cmdLeaveMonitor()
{
  uchar t[] = { 0x46, 0x01, 0x00, 0x60, 0xc0 };
  iface->send_Local (CArray (t, sizeof (t)));
  // pth_usleep (1000000);
}

void
EMI1Driver::cmdOpen ()
{
  const uchar ta[] = { 0x46, 0x01, 0x01, 0x16, 0x00 }; // clear addr tab
  const uchar t[] = { 0x46, 0x01, 0x00, 0x60, 0x12 };
  iface->send_Local (CArray (ta, sizeof (t)));
  iface->send_Local (CArray (t, sizeof (t)));
}

void
EMI1Driver::cmdClose ()
{
  uchar t[] = { 0x46, 0x01, 0x00, 0x60, 0xc0 };
  iface->send_Local (CArray (t, sizeof (t)));
}

const uint8_t *
EMI1Driver::getIndTypes()
{
    static const uint8_t indTypes[] = { 0x4E, 0x49, 0x49 };
    return indTypes;
}
