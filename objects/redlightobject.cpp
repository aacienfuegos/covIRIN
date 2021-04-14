#include "redlightobject.h"

/******************************************************************************/
/******************************************************************************/

CRedLightObject::CRedLightObject(const char* pch_name) : CGeometry(pch_name)
{
	m_dCenter.x=0.0;
	m_dCenter.y=0.0;
	m_fIntRadius=0.0;
	m_fExtRadius=0.0;
	m_fGrey=1.0;

	m_nVaccinesCapacity = 1;
	m_nVaccines = m_nVaccinesCapacity;
	m_nVaccinesThreshold = 0;
	m_nOutStepNumber=0;
	RECOVERY_TIME = 1000;

	m_nActivation = false;
}

/******************************************************************************/
/******************************************************************************/

CRedLightObject::~CRedLightObject(){
	
}

/******************************************************************************/
/******************************************************************************/

void CRedLightObject::SetColor(float fGrey){
	m_fGrey=fGrey;
}

/******************************************************************************/
/******************************************************************************/

void CRedLightObject::GetColor(float* fGrey){
	(*fGrey)=m_fGrey;
}

/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/******************************************************************************/

void CRedLightObject::SetHeight(float fHeight){
	m_fHeight=fHeight;
}

/******************************************************************************/
/******************************************************************************/

void CRedLightObject::GetHeight(float* fHeight){
	(*fHeight)=m_fHeight;
}

/******************************************************************************/
/******************************************************************************/

void CRedLightObject::SetCenter(dVector2 dCenter){
	m_dCenter=dCenter;
}

/******************************************************************************/
/******************************************************************************/

void CRedLightObject::GetCenter(dVector2 *dCenter){
	(*dCenter) = m_dCenter;
}

/******************************************************************************/
/******************************************************************************/

void CRedLightObject::SetIntRadius(float fRadius){
	m_fIntRadius=fRadius;
}

/******************************************************************************/
/******************************************************************************/

void CRedLightObject::GetIntRadius(float* fRadius){
	(*fRadius)=m_fIntRadius;
}

/******************************************************************************/
/******************************************************************************/

void CRedLightObject::SetExtRadius(float fRadius){
	m_fExtRadius=fRadius;
}

/******************************************************************************/
/******************************************************************************/

void CRedLightObject::GetExtRadius(float* fRadius){
	(*fRadius)=m_fExtRadius;
}

/******************************************************************************/
/******************************************************************************/

void CRedLightObject::Switch ( int n_value )
{
	if ( n_value == 0)
		m_nActivation = false;
	else 
		m_nActivation = true;
}

/******************************************************************************/
/******************************************************************************/

int CRedLightObject::GetStatus ( void )
{
	return m_nActivation;
}

/******************************************************************************/
/******************************************************************************/

void CRedLightObject::Reset ( void )
{
  m_nActivation = false;
}

/******************************************************************************/
/******************************************************************************/

int CRedLightObject::GetTiming ( unsigned int n_step_number )
{

 /* printf("Light %s\n",GetName()); */
	/* Create sequence */
	//if ( !(n_step_number % 110) )
	//{
		/* toggle light */
	//	m_nActivation ^= 0x1;
	//}

	/* default return true */
	return m_nActivation;
}

/******************************************************************************/
/******************************************************************************/

void CRedLightObject::SetVaccines(int nVaccines){
	m_nVaccines=nVaccines;
}

/******************************************************************************/
/******************************************************************************/

int CRedLightObject::GetVaccines ( void )
{
	return m_nVaccines;
}

/******************************************************************************/
/******************************************************************************/

void CRedLightObject::SetVaccinesThreshold(int nVaccinesThreshold){
	m_nVaccinesThreshold=nVaccinesThreshold;
}

/******************************************************************************/
/******************************************************************************/

int CRedLightObject::GetVaccinesThreshold ( void )
{
	return m_nVaccinesThreshold;
}

/******************************************************************************/
/******************************************************************************/

void CRedLightObject::SetVaccinesCapacity (int nVaccinesCapacity)
{
	m_nVaccinesCapacity = nVaccinesCapacity;
}

/******************************************************************************/
/******************************************************************************/

int CRedLightObject::GetVaccinesCapacity ( void )
{
	return m_nVaccinesCapacity;
}

/******************************************************************************/
/******************************************************************************/

void CRedLightObject::SetOutStepNumber(unsigned int n_step_number){
	m_nOutStepNumber = n_step_number;
}

/******************************************************************************/
/******************************************************************************/

int CRedLightObject::GetOutStepNumber ( void )
{
	return m_nOutStepNumber;
}

/******************************************************************************/
/******************************************************************************/

int CRedLightObject::ResetVaccines ( unsigned int n_step_number)
{
  if(m_nActivation) m_nOutStepNumber = n_step_number;
  if ( (n_step_number - m_nOutStepNumber) >= RECOVERY_TIME )
  {
    /* toggle light */
    m_nActivation = 1;
	m_nVaccines = m_nVaccinesCapacity;
	
	// Reset Out Step Number
	m_nOutStepNumber = n_step_number;

  }

	/* default return true */
	return m_nActivation;

}
