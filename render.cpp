

#include "render.h"

/******************************************************************************/
/******************************************************************************/

CRender* CRender::m_pcRender = NULL;

/******************************************************************************/
/******************************************************************************/

//CRender::CRender(CSimulator* pc_simulator, CArguments* pc_renderer_arguments) :
CRender::CRender(CSimulator* pc_simulator) :
    m_fFrameRate(1),
    m_pcSimulator(pc_simulator),
    m_iFrame(0)
//    m_pcRendererArguments(pc_renderer_arguments)
{
    m_pcRender    = this;
}


/******************************************************************************/
/******************************************************************************/

CRender::~CRender()
{
  /*  if (m_pcRendererArguments != NULL)
    {
        delete m_pcRendererArguments;
    }*/
}

/******************************************************************************/
/******************************************************************************/

CRender* CRender::GetInstance()
{
    return m_pcRender;
}
        
/******************************************************************************/
/******************************************************************************/

void CRender::SetSimulator(CSimulator* pc_simulator)
{
    m_pcSimulator = pc_simulator;
}

/******************************************************************************/
/******************************************************************************/

void CRender::SetFrameRate(double f_frame_rate)
{
    m_fFrameRate = f_frame_rate;

}

/******************************************************************************/
/******************************************************************************/

void CRender::DrawIndicator(float f_x, float f_y, float f_color_red, float f_color_green, float f_color_blue)
{
    // Nothing;

}

/******************************************************************************/
/******************************************************************************/

void CRender::dumpCurrentFrame()
{
}

/******************************************************************************/
/******************************************************************************/

void CRender::SetProduceFrames(bool b)
{
	m_bProduceFrames = b;
}

/******************************************************************************/
/******************************************************************************/