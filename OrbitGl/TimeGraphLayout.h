//-----------------------------------
// Copyright Pierric Gimmig 2013-2017
//-----------------------------------
#pragma once
#include <map>
#include <unordered_map>
#include <vector>
#include "CallstackTypes.h"
#include "CoreMath.h"
#include "ThreadTrack.h"


//-----------------------------------------------------------------------------
class TimeGraphLayout
{
public:
    TimeGraphLayout();

    float GetCoreOffset( int a_CoreId );
    float GetThreadStart();
    float GetThreadBlockStart( ThreadID a_TID );
    float GetThreadOffset( ThreadID a_TID, int a_Depth = 0 );
    float GetTracksHeight();
    float GetThreadBlockHeight( ThreadID a_TID );
    float GetSamplingTrackOffset( ThreadID a_TID );
    float GetFileIOTrackOffset( ThreadID a_TID );
    float GetTotalHeight();
    float GetTextBoxHeight() const { return m_TextBoxHeight; }
    float GetTextCoresHeight() const { return m_CoresHeight; }
    float GetEventTrackHeight() const { return m_EventTrackHeight; }
    void CalculateOffsets( ThreadTrackMap& a_ThreadTracks );
    void Reset();

    Color GetThreadColor( ThreadID a_TID ) const;
    void SetThreadColor( ThreadID a_TID, Color a_Color );
    void ClearThreadColors() { m_ThreadColors.clear(); }
    void SetThreadDepths( const std::map< ThreadID, int > & a_ThreadDepths ) { m_ThreadDepths = a_ThreadDepths; }
    void SetSortedThreadIds( const std::vector< ThreadID >& a_SortedThreadIds ) { m_SortedThreadIds = a_SortedThreadIds; }
    const std::vector< ThreadID >& GetSortedThreadIds() const { return m_SortedThreadIds; }

protected:
    int m_NumCores;
    int m_NumTracksPerThread;

    bool m_DrawFileIO;

    float m_WorldY;

    float m_TextBoxHeight;
    float m_CoresHeight;
    float m_EventTrackHeight;

    float m_SpaceBetweenCores;
    float m_SpaceBetweenCoresAndThread;
    float m_SpaceBetweenTracks;
    float m_SpaceBetweenTracksAndThread;
    float m_SpaceBetweenThreadBlocks;

    int m_NumTracks;

    std::map< ThreadID, int >   m_ThreadDepths;
    std::map< ThreadID, float > m_ThreadBlockOffsets;
    std::vector< ThreadID >     m_SortedThreadIds;

    std::unordered_map< ThreadID, Color > m_ThreadColors;
};