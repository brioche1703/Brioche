#pragma once

#include "Brioche/Layer.h"

#include "Brioche/Events/ApplicationEvent.h"
#include "Brioche/Events/KeyEvent.h"
#include "Brioche/Events/MouseEvent.h"

namespace Brioche {

	class BRIOCHE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override; 

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}
