#!/bin/bash

# ============================================================
#  Script de tests - RPN CPP Module 09 - 42
# ============================================================

BINARY="./RPN"
PASS=0
FAIL=0
ERRORS=0

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
BOLD='\033[1m'
RESET='\033[0m'

# Check binary exists
if [ ! -f "$BINARY" ]; then
    echo -e "${RED}❌ Binary '$BINARY' not found. Compile first.${RESET}"
    exit 1
fi

# ============================================================
#  Helpers
# ============================================================

run_test() {
    local description="$1"
    local input="$2"
    local expected="$3"

    if [ "$input" = "__NO_ARG__" ]; then
        actual=$(${BINARY} 2>/dev/null)
        actual_err=$(${BINARY} 2>&1 >/dev/null)
    else
        actual=$(${BINARY} "$input" 2>/dev/null)
        actual_err=$(${BINARY} "$input" 2>&1 >/dev/null)
    fi

    if [ "$expected" = "ERROR" ]; then
        # On attend une erreur : stdout vide ET stderr non vide
        if [ -z "$actual" ] && [ -n "$actual_err" ]; then
            echo -e "  ${GREEN}✅ PASS${RESET} | $description"
            ((PASS++))
        else
            echo -e "  ${RED}❌ FAIL${RESET} | $description"
            echo -e "       input    : '$input'"
            echo -e "       expected : Error on stderr, nothing on stdout"
            echo -e "       stdout   : '$actual'"
            echo -e "       stderr   : '$actual_err'"
            ((FAIL++))
        fi
    else
        if [ "$actual" = "$expected" ]; then
            echo -e "  ${GREEN}✅ PASS${RESET} | $description  →  ${BOLD}$actual${RESET}"
            ((PASS++))
        else
            echo -e "  ${RED}❌ FAIL${RESET} | $description"
            echo -e "       input    : '$input'"
            echo -e "       expected : '$expected'"
            echo -e "       got      : '$actual'"
            ((FAIL++))
        fi
    fi
}

print_section() {
    echo ""
    echo -e "${CYAN}${BOLD}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"
    echo -e "${CYAN}${BOLD}  $1${RESET}"
    echo -e "${CYAN}${BOLD}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"
}

# ============================================================
#  TESTS
# ============================================================

print_section "🟢 Opérations basiques"
run_test "Addition simple"        "3 4 +"    "7"
run_test "Soustraction simple"    "9 3 -"    "6"
run_test "Multiplication simple"  "3 4 *"    "12"
run_test "Division simple"        "8 2 /"    "4"
run_test "Résultat zéro"          "0 0 +"    "0"
run_test "Résultat négatif"       "3 9 -"    "-6"
run_test "Opérande zéro"          "0 5 *"    "0"
run_test "Division résultat 1"    "9 9 /"    "1"

print_section "🟡 Expressions composées"
run_test "Addition puis multiply"      "3 4 + 2 *"         "14"
run_test "Soustraction imbriquée"      "7 2 3 + -"         "2"
run_test "Division puis multiply"      "4 2 / 3 *"         "6"
run_test "Quatre additions"            "1 2 3 4 + + +"     "10"
run_test "Exemple sujet (→14)"         "5 1 2 + 4 * + 3 -" "14"

print_section "🔴 Expressions longues (sujet)"
run_test "Exemple sujet (→54)"  "8 9 * 9 - 1 - 1 8 * -"                       "54"
run_test "Expression longue (→15)" "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /" "15"

print_section "❌ Erreurs : pile insuffisante"
run_test "Opérateur seul"         "+"         "ERROR"
run_test "Un seul opérande"       "3 +"       "ERROR"
run_test "Opérateur sans pile"    "* 3 4"     "ERROR"

print_section "❌ Erreurs : pile trop grande"
run_test "3 chiffres, 1 op"    "3 4 5 +"   "ERROR"
run_test "Que des chiffres"    "1 2 3"     "ERROR"

print_section "❌ Erreurs : division par zéro"
run_test "Division par 0"       "5 0 /"    "ERROR"
run_test "Division par 0 (→0)"  "0 0 /"   "ERROR"

print_section "❌ Erreurs : caractères invalides"
run_test "Lettre dans expr"    "3 a +"    "ERROR"
run_test "Caractère spécial"   "3 @ +"   "ERROR"
run_test "Mot dans expr"       "hello"   "ERROR"
run_test "Underscore"          "3 _ +"   "ERROR"

print_section "❌ Erreurs : nombres >= 10"
run_test "Nombre 10"           "10 3 +"   "ERROR"
run_test "Grand nombre"        "3 42 +"   "ERROR"
run_test "Nombre 99"           "99 1 +"   "ERROR"

print_section "❌ Erreurs : arguments manquants / vides"
run_test "Argument vide"       ""            "ERROR"
run_test "Pas d'argument"      "__NO_ARG__"  "ERROR"

# ============================================================
#  RÉSUMÉ
# ============================================================

TOTAL=$((PASS + FAIL))
echo ""
echo -e "${BOLD}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"
echo -e "${BOLD}  RÉSUMÉ : $PASS / $TOTAL tests passés${RESET}"
if [ $FAIL -eq 0 ]; then
    echo -e "  ${GREEN}${BOLD}🎉 Tous les tests sont passés !${RESET}"
else
    echo -e "  ${RED}${BOLD}⚠️  $FAIL test(s) échoué(s)${RESET}"
fi
echo -e "${BOLD}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"
echo ""

[ $FAIL -eq 0 ] && exit 0 || exit 1