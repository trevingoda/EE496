/*
 * Copyright (C) 2014  RoboPeak
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
/*
 *  RoboPeak Lidar System
 *  Win32 Demo Application
 *
 *  Copyright 2009 - 2014 RoboPeak Team
 *  http://www.robopeak.com
 *
 */

// SerialSelDlg.cpp : implementation of the CSerialSelDlg class
//
/////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "resource.h"

#include "SerialSelDlg.h"

CSerialSelDlg::CSerialSelDlg()
    : selectedID(-1)
{
}

LRESULT CSerialSelDlg::OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	CenterWindow(GetParent());
    this->DoDataExchange();
    char buf[100]; 
    for (int pos= 0; pos<100; ++pos) {
        sprintf(buf,"COM%d",pos+1);
        m_sel_box.AddString(buf);
    }
    m_sel_box.SetCurSel(2);
    selectedID = 2;
	return TRUE;
}

LRESULT CSerialSelDlg::OnOK(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	EndDialog(wID);
	return 0;
}

LRESULT CSerialSelDlg::OnCancel(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	EndDialog(wID);
	return 0;
}

LRESULT CSerialSelDlg::OnCbnSelchangeCombSerialSel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
    selectedID = m_sel_box.GetCurSel();
	return 0;
}
