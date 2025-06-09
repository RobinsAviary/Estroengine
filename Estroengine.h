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
			Node* parent = nullptr; // nullptr is used when a value is not yet set. This can be checked by going, for example, if (parent) {//codegoeshere}
			
			virtual void step();
			virtual void draw();
			virtual void onCreate();
			virtual void onDestroy();

			List<Node*> getChildren();
			List<Node*> getAncestors();
			List<Node*> getSiblings();
			List<Node*> getDescendants();

			List<Node*> getChildrenTagged(const std::string &tag);
			List<Node*> getAncestorsTagged(const std::string &tag);
			List<Node*> getSiblingsTagged(const std::string &tag);
			List<Node*> getDescendantsTagged(const std::string &tag);

			Node* getChildTagged(const std::string &tag);
			Node* getAncestorTagged(const std::string &tag);
			Node* getSiblingTagged(const std::string &tag);
			Node* getDescendantTagged(const std::string &tag);

			void destroy();

			void destroyChildTagged(const std::string &tag);
			void destroyAncestorTagged(const std::string &tag);
			void destroySiblingTagged(const std::string &tag);
			void destroyDescendantTagged(const std::string &tag);

			void destroyChildrenTagged(const std::string &tag);
			void destroyAncestorsTagged(const std::string &tag);
			void destroySiblingsTagged(const std::string &tag);
			void destroyDescendantsTagged(const std::string &tag);

			void addTag(const std::string &tag);
			void removeTag(const std::string &tag);
			bool hasTag(const std::string &tag);
			List<std::string> getTags();

			template <typename nodeType>
			nodeType* addNode() {
				nodeType* node = new nodeType;
				_children.add(node);

				return node;
			}

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
			void step() override;
			void draw() override;
			void update();

		protected:
			static void garbageCollect();

		private:

	};
}