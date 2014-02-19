/*
 * (C) 2012-2014 see Authors.txt
 *
 * This file is part of MPC-HC.
 *
 * MPC-HC is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * MPC-HC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#pragma once

#include "sizecbar/scbarg.h"


class CPlayerBar : public CSizingControlBarG
{
    friend class CMainFrameControls; // for accessing m_szMinVert, m_szMinHorz and m_cxEdge

    DECLARE_DYNAMIC(CPlayerBar)

    bool m_bAutohidden;
    bool m_bHasActivePopup;

protected:
    DECLARE_MESSAGE_MAP()

    UINT m_defDockBarID;
    CString m_strSettingName;

    afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
    afx_msg void OnEnterMenuLoop(BOOL bIsTrackPopupMenu);
    afx_msg void OnExitMenuLoop(BOOL bIsTrackPopupMenu);

public:
    CPlayerBar();
    virtual ~CPlayerBar();

    BOOL Create(LPCTSTR lpszWindowName, CWnd* pParentWnd, UINT nID, UINT defDockBarID, CString const& strSettingName);

    virtual void LoadState(CFrameWnd* pParent);
    virtual void SaveState();

    void Autohidden(bool bValue);
    bool Autohidden() const;
    bool HasActivePopup() const;
};
