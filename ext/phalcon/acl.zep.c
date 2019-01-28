
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Acl
 *
 * This component allows to manage ACL lists. An access control list (ACL) is a list
 * of permissions attached to an object. An ACL specifies which users or system processes
 * are granted access to objects, as well as what operations are allowed on given objects.
 *
 *<code>
 * use Phalcon\Acl;
 * use Phalcon\Acl\Operation;
 * use Phalcon\Acl\Subject;
 * use Phalcon\Acl\Adapter\Memory;
 *
 * $acl = new Memory();
 *
 * // Default action is deny access
 * $acl->setDefaultAction(Acl::DENY);
 *
 * // Create some operations
 * $adminsOperation = new Operation("Administrators", "Super-User role");
 * $guestsOperation = new Operation("Guests");
 *
 * // Add "Guests" operation to acl
 * $acl->addOperation($roleGuests);
 *
 * // Add "Designers" operation to acl
 * $acl->addOperation("Designers");
 *
 * // Define the "Customers" subject
 * $customersSubject = new Subject("Customers", "Customers management");
 *
 * // Add "customers" subject with a couple of operations
 * $acl->addSubject($customersSubject, "search");
 * $acl->addSubject($customersSubject, ["create", "update"]);
 *
 * // Set access level for operations into subjects
 * $acl->allow($guestsOperation->getName(), "Customers", "search");
 * $acl->allow("Guests", "Customers", "create");
 * $acl->deny($guestsOperation->getName(), "Customers", "update");
 *
 * // Check whether operation has access to the operations
 * $acl->isAllowed("Guests", "Customers", "edit"); // Returns 0
 * $acl->isAllowed($guestsOperation->getName(), "Customers", "search"); // Returns 1
 * $acl->isAllowed($guestsOperation->getName(), "Customers", "create"); // Returns 1
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Acl, phalcon, acl, NULL, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zephir_declare_class_constant_long(phalcon_acl_ce, SL("ALLOW"), 1);

	zephir_declare_class_constant_long(phalcon_acl_ce, SL("DENY"), 0);

	return SUCCESS;

}

