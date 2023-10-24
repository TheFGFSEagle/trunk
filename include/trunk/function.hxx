#ifndef TRUNK_FUNCTION_HXX
#define TRUNK_FUNCTION_HXX

#include <trunk/reference.hxx>
#include <trunk/object.hxx>

namespace trunk {
	class Function: public Object {
		using Callable = Reference (*)(Reference);
		
		public:
			Function(Callable callable): _callable(callable) {}
			
			virtual const std::string name() { return "Function"; }
			Callable get_cpp_object() { return _callable; }
			
			Reference operator()(Reference args) {
				if (_callable) {
					return _callable(args);
				}
				return {};
			}
		
		protected:
			Callable _callable;
	};
}

#endif

