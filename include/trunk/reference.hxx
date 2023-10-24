#ifndef TRUNK_REFERENCE_HXX
#define TRUNK_REFERENCE_HXX

#include <trunk/object.hxx>
#include <trunk/string.hxx>

namespace trunk {
	typedef union {
		Object* object;
	} ReferencePtr;
	
	class Reference {
		public:
			Reference() {};
			Reference(Object* object) {
				_ptr.object = object;
			}
			Reference(std::string s) {
				_ptr.object = new String(s);
			}
			
			template<typename T = trunk::Object>
			T* get_object() {
				return dynamic_cast<T*>(_ptr.object);
			}
		
		protected:
			ReferencePtr _ptr;
	};
}

#endif

