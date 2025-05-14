#pragma once

#include <string> // Used for text
#include "Estroimpl.h"
#include "Estrodefs.h" // Used for TemplateType
#include "Estrolist.h" // Used for lists
#include "Estrocolors.h"
#include "Estrovector.h"

namespace Estro {
	class Node {
		public:
			Node* parent = NULL; // NULL is used when a value is not yet set. This can be checked by going, for example, if (parent) {//codegoeshere}
			
			virtual void step();
			virtual void draw();
			virtual void onCreate();
			virtual void onDestroy();

			List<Node*> getChildren();
			List<Node*> getAncestors();
			List<Node*> getSiblings();
			List<Node*> getDescendants();

			List<Node*> getChildrenTagged(std::string tag);
			List<Node*> getAncestorsTagged(std::string tag);
			List<Node*> getSiblingsTagged(std::string tag);
			List<Node*> getDescendantsTagged(std::string tag);

			Node* getChildTagged(std::string tag);
			Node* getAncestorTagged(std::string tag);
			Node* getSiblingTagged(std::string tag);
			Node* getDescendantTagged(std::string tag);

			void addTag(std::string tag);
			void removeTag(std::string tag);
			bool hasTag(std::string tag);
			List<std::string> getTags();

			template <typename nodeType>
			nodeType* addNode();

			Node* getRoot();

			//unsigned int getHandle();

		private:


		protected:
			unsigned int _handle = 0; // TODO: Implement.
			List<Node*> _children;
			List<std::string> _tags;
	};

	class Engine : public Node {
		public:
			void step();
			void draw();
			void update();

		protected:
			void garbageCollect();

		private:

	};
}