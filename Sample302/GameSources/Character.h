/*!
@file Character.h
@brief ƒLƒƒƒ‰ƒNƒ^[‚È‚Ç
*/

#pragma once
#include "stdafx.h"

namespace basecross{


	//--------------------------------------------------------------------------------------
	//	class FixedBox : public GameObject;
	//--------------------------------------------------------------------------------------
	class FixedBox : public GameObject {
		Vec3 m_Scale;
		Vec3 m_Rotation;
		Vec3 m_Position;
	public:
		//\’z‚Æ”jŠü
		FixedBox(const shared_ptr<Stage>& StagePtr,
			const Vec3& Scale,
			const Vec3& Rotation,
			const Vec3& Position
		);
		virtual ~FixedBox();
		//‰Šú‰»
		virtual void OnCreate() override;
		//‘€ì
	};

	//--------------------------------------------------------------------------------------
	//	class HitTestSphere : public GameObject;
	//--------------------------------------------------------------------------------------
	class HitTestSphere : public GameObject {
		float m_Scale;
		Vec3 m_Position;
	public:
		//\’z‚Æ”jŠü
		HitTestSphere(const shared_ptr<Stage>& StagePtr,
			float Scale,
			const Vec3& Position
		);
		virtual ~HitTestSphere();
		//‰Šú‰»
		virtual void OnCreate() override;
		//‘€ì
		virtual void OnUpdate() override;
		//Ä•`‰æ
		void Wakeup();
	};



}
//end basecross
