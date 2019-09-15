/*!
@file Character.cpp
@brief �L�����N�^�[�Ȃǎ���
*/

#include "stdafx.h"
#include "Project.h"

namespace basecross{


	//--------------------------------------------------------------------------------------
	//	class FixedBox : public GameObject;
	//--------------------------------------------------------------------------------------
	//�\�z�Ɣj��
	FixedBox::FixedBox(const shared_ptr<Stage>& StagePtr,
		const Vec3& Scale,
		const Vec3& Rotation,
		const Vec3& Position
	) :
		GameObject(StagePtr),
		m_Scale(Scale),
		m_Rotation(Rotation),
		m_Position(Position)
	{
	}
	FixedBox::~FixedBox() {}

	//������
	void FixedBox::OnCreate() {
		auto ptrTransform = GetComponent<Transform>();
		ptrTransform->SetScale(m_Scale);
		ptrTransform->SetRotation(m_Rotation);
		ptrTransform->SetPosition(m_Position);
		//OBB�Փ�j�����t����
		auto ptrColl = AddComponent<CollisionObb>();
		ptrColl->SetFixed(true);
		//�^�O������
		AddTag(L"FixedBox");
		//�e������i�V���h�E�}�b�v��`�悷��j
		auto ptrShadow = AddComponent<Shadowmap>();
		//�e�̌`�i���b�V���j��ݒ�
		ptrShadow->SetMeshResource(L"DEFAULT_CUBE");
		auto ptrDraw = AddComponent<BcPNTStaticDraw>();
		ptrDraw->SetMeshResource(L"DEFAULT_CUBE");
		ptrDraw->SetTextureResource(L"SKY_TX");
		ptrDraw->SetFogEnabled(true);
		ptrDraw->SetOwnShadowActive(true);

	}


	//--------------------------------------------------------------------------------------
	//	class HitTestSphere : public GameObject;
	//--------------------------------------------------------------------------------------
		//�\�z�Ɣj��
	HitTestSphere::HitTestSphere(const shared_ptr<Stage>& StagePtr,
			float Scale,
			const Vec3& Position
		):
		GameObject(StagePtr),
		m_Scale(Scale),
		m_Position(Position)
	{}
	HitTestSphere::~HitTestSphere() {
	}
	//������
	void HitTestSphere::OnCreate() {
		auto ptrTransform = GetComponent<Transform>();
		ptrTransform->SetScale(Vec3(m_Scale));
		ptrTransform->SetRotation(Vec3(0));
		ptrTransform->SetPosition(m_Position);
		//�e������i�V���h�E�}�b�v��`�悷��j
		auto ptrShadow = AddComponent<Shadowmap>();
		//�e�̌`�i���b�V���j��ݒ�
		ptrShadow->SetMeshResource(L"DEFAULT_SPHERE");
		auto ptrDraw = AddComponent<BcPNTStaticDraw>();
		ptrDraw->SetMeshResource(L"DEFAULT_SPHERE");
		ptrDraw->SetTextureResource(L"BROWN_TX");
		ptrDraw->SetFogEnabled(true);

	}

	extern "C" int CollisionSp(SPHERE* sp1, SPHERE* sp2);

	//����
	void HitTestSphere::OnUpdate() {

		SPHERE sp1;
		sp1.m_Center = m_Position;
		sp1.m_Radius = m_Scale / 2;

		auto ptrPlayer = GetStage()->GetSharedGameObject<Player>(L"Player");
		auto sp2 = ptrPlayer->GetComponent<CollisionSphere>()->GetSphere();
		if (CollisionSp(&sp1, &sp2)) {
			SetUpdateActive(false);
			SetDrawActive(false);
			auto ptrShadow = AddComponent<Shadowmap>();
			ptrShadow->SetDrawActive(false);
		}

	}

	void HitTestSphere::Wakeup() {
		SetUpdateActive(true);
		SetDrawActive(true);
		auto ptrShadow = AddComponent<Shadowmap>();
		ptrShadow->SetDrawActive(true);
	}



}
//end basecross
