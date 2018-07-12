using VecSolutionsForSums = std::vector<bool>;
using VecSolutionsForSizeAndSums = std::vector<VecSolutionsForSums>;
using Opt = std::vector<VecSolutionsForSizeAndSums>;

/**
 * @result The indices of the the items.
 */
static bool
get_set_with_size_and_sum(const std::vector<int>& available,
    std::size_t i, std::size_t size, int sum, Opt& opt, std::vector<int>& set) {
  const auto n = available.size();

  if (size == 0) {
    return sum == 0;
  }

  if (i >= n) {
    return false;
  }

  if (size > n) {
    return false;
  }

  // Return cached results:
  auto& opti = opt[i][size];
  const auto c = opti[sum];
  if (!c) {
    return c;
  }

  // Try with the current item:
  const auto v = available[i];
  if (sum >= v) {
    set.emplace_back(v);
    if (get_set_with_size_and_sum(available,
      i + 1, size - 1, sum - v, opt, set)) {
      //assert(!(set.size() > size));
      return true;
    }
    set.pop_back();
  }

  // Try without using the current item:
  if (get_set_with_size_and_sum(
    available, i + 1, size, sum, opt, set)) {
    return true;
  }
  //assert(!(set.size() > size));

  return opti[sum] = false;
}

static std::vector<int>
get_set2(const std::vector<int>& available,
  const std::vector<int>& set1) {
  std::vector<int> result;
  const auto n = available.size();
  const auto s1n = set1.size();

  result.reserve(available.size() - set1.size());

  std::size_t j = 0;
  for (std::size_t i = 0; i < n; ++i) {
    const auto v  = available[i];
    if (j < s1n && v == set1[j]) {
      ++j;
      continue;
    }

    result.emplace_back(v);
  }

  return result;
}

vector<vector<int> > Solution::avgset(vector<int> &A) {
  const auto n = A.size();
  if (n < 2) {
    return {};
  }

  const int total = std::accumulate(std::begin(A), std::end(A), 0);

  // So that a sorted vector of indices
  // represents a sorted vector of values:
  std::sort(std::begin(A), std::end(A));

  Opt opt(n + 1, VecSolutionsForSizeAndSums(n + 1, VecSolutionsForSums(total, true)));

  const auto half = ((n + 1) / 2);
  for (auto i = 1u; i <= half; ++i) {
    // The sum must be an integer:
    // Instead of just checking average * i,
    // which is total/n * i, we check total * i / n,
    // so we can do the % check last.
    const auto totalmi = total * i;
    if (totalmi % n != 0) {
      continue;
    }
 
    const auto sum = (total * i) / n;

    std::vector<int> set1;
    set1.reserve(n);
    if (!get_set_with_size_and_sum(A, 0, i, sum, opt, set1)) {
      continue;
    }

    const auto set2 = get_set2(A, set1);
    if (!set2.empty()) {

      // Return the result:
      //std::sort(std::begin(set1v), std::end(set1v));
      //std::sort(std::begin(set2v), std::end(set2v));
      return {set1, set2};
    }
  }

  return {};
}