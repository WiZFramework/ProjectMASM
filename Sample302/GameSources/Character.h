/*!
@file Character.h
@brief �L�����N�^�[�Ȃ�
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
		//�\�z�Ɣj��
		FixedBox(const shared_ptr<Stage>& StagePtr,
			const Vec3& Scale,
			const Vec3& Rotation,
			const Vec3& Position
		);
		virtual ~FixedBox();
		//������
		virtual void OnCreate() override;
		//����
	};

	//--------------------------------------------------------------------------------------
	//	class HitTestSphere : public GameObject;
	//--------------------------------------------------------------------------------------
	class HitTestSphere : public GameObject {
		float m_Scale;
		Vec3 m_Position;
	public:
		//�\�z�Ɣj��
		HitTestSphere(const shared_ptr<Stage>& StagePtr,
			float Scale,
			const Vec3& Position
		);
		virtual ~HitTestSphere();
		//������
		virtual void OnCreate() override;
		//����
		virtual void OnUpdate() override;
		//�ĕ`��
		void Wakeup();
	};



}
//end basecross
