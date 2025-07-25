#include "variant.h"

#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <variant>

struct variant_t
{
	std::variant<std::monostate, variant_int, variant_string> v;
};

VEXTERN variant_t *variant_create(void)
{
	variant_t *object = (variant_t *)malloc(sizeof(variant_t));
	object->v = (variant_int)0;

	if (object == NULL)
	{
#ifdef V_DEBUG
		printf("variant_create(): Could not allocate memory\n");
#endif /* V_DEBUG */
		return NULL;
	}

	return object;
}

VEXTERN void variant_destroy(variant_t *object)
{
	if (object == NULL) return;
#ifdef V_DEBUG
	printf("variant_destroy(): Destroyed variant object\n");
#endif /* V_DEBUG */

	free(object);
}

VEXTERN void variant_store_int(variant_t *object, variant_int value)
{
	if (object == NULL) return;
#ifdef V_DEBUG
	printf("variant_store_int():\n");
#endif /* V_DEBUG */

	object->v = (variant_int)value;
}

VEXTERN variant_int variant_load_int(variant_t *object)
{
	if (std::holds_alternative<variant_int>(object->v))
		return std::get<variant_int>(object->v);
#ifdef V_DEBUG
	printf("variant_load_int():\n");
#endif /* V_DEBUG */

	return 0;
}

VEXTERN void variant_store_string(variant_t *object, variant_string value)
{
	if (object == NULL) return;
#ifdef V_DEBUG
	printf("variant_store_string():\n");
#endif /* V_DEBUG */

	object->v = (variant_string)value;
}

VEXTERN variant_string variant_load_string(variant_t *object)
{
	if (std::holds_alternative<variant_string>(object->v))
		return std::get<variant_string>(object->v);
#ifdef V_DEBUG
	printf("variant_load_string():\n");
#endif /* V_DEBUG */

	return NULL;
}
